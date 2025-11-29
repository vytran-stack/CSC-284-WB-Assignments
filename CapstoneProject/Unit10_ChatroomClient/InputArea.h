
#pragma once
#include "Window.h"
#include <string>

class InputArea : public Window {
    std::string buffer;

public:
    InputArea(int h, int w, int y, int x);

    void handleInput(int ch);
    std::string getText();
    void clearBuffer();
    void draw();
};
