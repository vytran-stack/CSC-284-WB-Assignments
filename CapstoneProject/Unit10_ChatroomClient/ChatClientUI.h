
#pragma once
#include "RoomList.h"
#include "MessageArea.h"
#include "InputArea.h"

class ChatClientUI {
    Window* header;
    RoomList* roomList;
    MessageArea* messageArea;
    InputArea* inputArea;

public:
    ChatClientUI();
    ~ChatClientUI();
    void run();

private:
    void initLayout();
    void initSampleData();
    void drawAll();
    void handleKey(int ch, bool& running);
};
