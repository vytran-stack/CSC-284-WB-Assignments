#include <winsock2.h>
#include <ws2tcpip.h>
#include <thread>
#include <atomic>
#include <string>

#include <curses.h>
#include "ChatClientUI.h"

#pragma comment(lib, "ws2_32.lib")

std::atomic<bool> running(true);

void recvThread(SOCKET sock, ChatClientUI* ui) {
    char buf[4096];

    while (running) {
        int bytes = recv(sock, buf, sizeof(buf) - 1, 0);
        if (bytes <= 0) break;

        buf[bytes] = '\0';
        ui->addMessage(std::string(buf));
    }

    running = false;
}

int main(int argc, char* argv[]) {

    //Init Winsock
    WSADATA data;
    WSAStartup(MAKEWORD(2, 2), &data);

    std::string ip = "127.0.0.1";
    int port = 54000;

    if (argc >= 2) ip = argv[1];
    if (argc >= 3) port = std::stoi(argv[2]);

    //Create socket
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in hint{};
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &hint.sin_addr);

    connect(sock, (sockaddr*)&hint, sizeof(hint));

    //Init UI
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    ChatClientUI ui;

    //UI → server
    ui.setSendCallback([&](const std::string& msg) {
        send(sock, msg.c_str(), msg.size(), 0);
    });

    //Start receiving thread (server → UI)
    std::thread t(recvThread, sock, &ui);

    //Start UI loop
    ui.run();

    //Cleanup
    running = false;
    closesocket(sock);
    t.join();

    endwin();
    WSACleanup();
    return 0;
}
