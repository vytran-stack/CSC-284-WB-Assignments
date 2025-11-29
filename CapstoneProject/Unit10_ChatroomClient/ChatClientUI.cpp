
#include "ChatClientUI.h"

ChatClientUI::ChatClientUI() {
    initLayout();
    initSampleData();
}

ChatClientUI::~ChatClientUI() {}

void ChatClientUI::initLayout() {
    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    int headerH = 3;
    int inputH = 3;
    int middleH = rows - headerH - inputH;
    int roomW = cols / 4;

    header = new Window(headerH, cols, 0, 0);
    roomList = new RoomList(middleH, roomW, headerH, 0);
    messageArea = new MessageArea(middleH, cols - roomW, headerH, roomW);
    inputArea = new InputArea(inputH, cols, headerH + middleH, 0);
}

void ChatClientUI::initSampleData() {
    roomList->setRooms({"General", "Sports", "Programming"});

    messageArea->setMessages({
        "Welcome to the chat!",
        "You are in room: General",
        "This is a placeholder message"
    });
}

void ChatClientUI::drawAll() {
    header->clearContent();
    header->drawBorder();
    mvwprintw(header->getWin(), 1, 2, "Advanced C++ Chat Client");
    header->refreshWin();

    roomList->draw();
    messageArea->draw();
    inputArea->draw();
}

void ChatClientUI::handleKey(int ch, bool& running) {
    switch (ch) {
    case KEY_UP: roomList->moveUp(); break;
    case KEY_DOWN: roomList->moveDown(); break;
    case 27: running = false; break;
    case '\n':
        messageArea->setMessages({
            "You typed: " + inputArea->getText()
        });
        inputArea->clearBuffer();
        break;
    default:
        inputArea->handleInput(ch);
        break;
    }
}

void ChatClientUI::run() {
    bool running = true;
    drawAll();

    while (running) {
        int ch = getch();
        handleKey(ch, running);
        drawAll();
    }
}
