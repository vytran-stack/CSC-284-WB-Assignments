
#pragma once
#include <functional>

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

    void addMessage(const std::string& msg) ;
    void setSendCallback(std::function<void(const std::string&)>&& cb);
private:
    std::function<void(const std::string&)> sendCallback;
    void initLayout();
    void initSampleData();
    void drawAll();
    void handleKey(int ch, bool& running);

};
