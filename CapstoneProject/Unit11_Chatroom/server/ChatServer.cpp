#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>
#include <cstring>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define closesocket close
#endif

//
std::vector<SOCKET> g_clients;
std::mutex g_clientsMutex;

void broadcastMessage(const std::string& msg, SOCKET sender)
{
    std::lock_guard<std::mutex> lock(g_clientsMutex);

    for (SOCKET clientSock : g_clients)
    {
        // Nếu không muốn gửi lại cho thằng gửi thì bỏ comment:
        // if (clientSock == sender) continue;

        int sendResult = send(clientSock, msg.c_str(), (int)msg.size(), 0);
        if (sendResult == SOCKET_ERROR)
        {
            std::cerr << "Send failed to a client\n";
        }
    }
}
// Thread xử lý từng client
void handleClient(SOCKET clientSocket)
{
    char buffer[4096];

    while (true)
    {
        memset(buffer, 0, 4096);

        int bytesReceived = recv(clientSocket, buffer, 4096, 0);
        if (bytesReceived <= 0)
        {
            std::cout << "Client disconnected\n";
            break;
        }

        std::string msg(buffer, bytesReceived);
        std::cout << "Client says: " << msg << std::endl;

        // Broadcast cho tất cả client khác
        broadcastMessage(msg, clientSocket);
    }

    // Xóa client khỏi danh sách
    {
        std::lock_guard<std::mutex> lock(g_clientsMutex);
        auto it = std::remove(g_clients.begin(), g_clients.end(), clientSocket);
        g_clients.erase(it, g_clients.end());
    }

    closesocket(clientSocket);
}


int main(int argc, char* argv[])
{
#ifdef _WIN32
    WSADATA data;
    WSAStartup(MAKEWORD(2, 2), &data);
#endif
    std::string ip = "127.0.0.1";
    unsigned short port = 54000;

    if (argc >= 2)
    {
        ip = argv[1];
    }
    if (argc >= 3)
    {
        port = static_cast<unsigned short>(std::stoi(argv[2]));
    }

    std::cout << "Server starting at " << ip << ":" << port << std::endl;

    SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == INVALID_SOCKET)
    {
        std::cerr << "Can't create socket" << std::endl;
#ifdef _WIN32
        WSACleanup();
#endif
        return 1;
    }


    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    // chuyển chuỗi IP thành dạng nhị phân
    inet_pton(AF_INET, ip.c_str(), &hint.sin_addr);

    if (bind(listening, (sockaddr*)&hint, sizeof(hint)) == SOCKET_ERROR)
    {
        std::cerr << "Bind failed" << std::endl;
        closesocket(listening);
#ifdef _WIN32
        WSACleanup();
#endif
        return 1;
    }
    if (listen(listening, SOMAXCONN) == SOCKET_ERROR)
    {
        std::cerr << "Listen failed" << std::endl;
        closesocket(listening);
#ifdef _WIN32
        WSACleanup();
#endif
        return 1;
    }

    std::cout << "Server is listening..." << std::endl;

    // Vòng lặp accept nhiều client
    while (true)
    {
        sockaddr_in client;
        socklen_t clientSize = sizeof(client);

        SOCKET clientSocket = accept(listening, (sockaddr*)&client, &clientSize);
        if (clientSocket == INVALID_SOCKET)
        {
            std::cerr << "Accept failed" << std::endl;
            continue;
        }

        char host[NI_MAXHOST];
        char service[NI_MAXSERV];

        memset(host, 0, NI_MAXHOST);
        memset(service, 0, NI_MAXSERV);

        if (getnameinfo((sockaddr*)&client, sizeof(client), host, NI_MAXHOST,
                        service, NI_MAXSERV, 0) == 0)
        {
            std::cout << "New connection from " << host << " on port " << service << std::endl;
        }
        else
        {
            inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
            std::cout << "New connection from " << host << " on port "
                      << ntohs(client.sin_port) << std::endl;
        }

        {
            std::lock_guard<std::mutex> lock(g_clientsMutex);
            g_clients.push_back(clientSocket);
        }

        // Tạo thread riêng cho client này
        std::thread t(handleClient, clientSocket);
        t.detach();
    }


#ifdef _WIN32
    WSACleanup();
#endif

    return 0;
}