#include <iostream>
#include <string>
#include <thread>
#include <atomic>
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

int main(int argc, char* argv[])

{
#ifdef _WIN32
    WSADATA data;
    WSAStartup(MAKEWORD(2, 2), &data);
#endif


    // 2. Đọc IP và port từ command line
    // ./client
    // ./client <ip>
    // ./client <ip> <port>
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

    std::cout << "Client connecting to " << ip << ":" << port << "\n";

    // 3. Tạo socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET)
    {
        std::cerr << "Can't create socket.\n";
        WSACleanup();
        return 1;
    }

    sockaddr_in serverHint;
    serverHint.sin_family = AF_INET;
    serverHint.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &serverHint.sin_addr);

    int connResult = connect(sock, (sockaddr*)&serverHint, sizeof(serverHint));
    if (connResult == SOCKET_ERROR)
    {
        std::cerr << "Can't connect to server. Error: " << WSAGetLastError() << "\n";
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    std::cout << "Connected to server.\n";
    std::cout << "Type messages and press Enter.\n";
    std::cout << "Type 'quit' to exit.\n";

    std::atomic<bool> running(true);

    // 4. Thread nhận message từ server (background)
    std::thread receiveThread([&]() {
        char buffer[4096];

        while (running)
        {
            memset(buffer, 0, sizeof(buffer));

            int bytesReceived = recv(sock, buffer, sizeof(buffer), 0);
            if (bytesReceived <= 0)
            {
                std::cout << "\nServer disconnected or error.\n";
                running = false;
                break;
            }

            std::string msg(buffer, bytesReceived);
            std::cout << "\n" << msg << "\n";
            std::cout << "> " << std::flush; // in lại prompt
        }
    });

    // 5. Thread chính: đọc input và gửi lên server
    std::string input;
    std::cout << "> " << std::flush;

    while (running && std::getline(std::cin, input))
    {
        if (input == "quit")
        {
            running = false;
            break;
        }

        if (input.empty())
        {
            std::cout << "> " << std::flush;
            continue;
        }

        int sendResult = send(sock, input.c_str(), (int)input.size(), 0);
        if (sendResult == SOCKET_ERROR)
        {
            std::cerr << "Send failed. Error: " << WSAGetLastError() << "\n";
            running = false;
            break;
        }

        std::cout << "> " << std::flush;
    }

    // 6. Dọn dẹp
    closesocket(sock);

    if (receiveThread.joinable())
    {
        receiveThread.join();
    }

    WSACleanup();
    std::cout << "Client exited.\n";
    return 0;
}