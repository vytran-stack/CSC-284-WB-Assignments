
#pragma once
#include "Window.h"
#include <vector>
#include <string>

class MessageArea : public Window {
    std::vector<std::string> messages;

public:
    MessageArea(int h, int w, int y, int x);
    void setMessages(const std::vector<std::string>& msgs);
    void draw();
};
