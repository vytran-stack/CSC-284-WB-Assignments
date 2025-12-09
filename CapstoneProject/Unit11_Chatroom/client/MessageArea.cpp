
#include "MessageArea.h"

MessageArea::MessageArea(int h, int w, int y, int x)
    : Window(h, w, y, x) {}


void MessageArea::draw() {
    clearContent();
    drawBorder();

    int line = 1;
    for (auto& msg : messages) {
        if (line < height - 1)
            mvwprintw(win, line++, 2, "%s", msg.c_str());
    }
    refreshWin();

}
void MessageArea::addLine(const std::string& msg) {
    messages.push_back(msg);
}



