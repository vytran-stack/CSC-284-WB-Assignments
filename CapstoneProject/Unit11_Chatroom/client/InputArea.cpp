
#include "InputArea.h"

InputArea::InputArea(int h, int w, int y, int x)
    : Window(h, w, y, x) {}

void InputArea::handleInput(int ch) {
    if (ch == KEY_BACKSPACE || ch == 127) {
        if (!buffer.empty()) buffer.pop_back();
    }
    else if (isprint(ch)) {
        buffer.push_back((char)ch);
    }
}

std::string InputArea::getText() { return buffer; }

void InputArea::clearBuffer() { buffer.clear(); }

void InputArea::draw() {
    clearContent();
    drawBorder();
    mvwprintw(win, 1, 2, "Input: %s", buffer.c_str());
    refreshWin();
}
