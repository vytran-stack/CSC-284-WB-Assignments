
#include "Window.h"

Window::Window(int h, int w, int y, int x)
    : height(h), width(w), startY(y), startX(x)
{
    win = newwin(height, width, startY, startX);
}

Window::~Window() {
    delwin(win);
}

void Window::drawBorder() {
    box(win, 0, 0);
}

void Window::clearContent() {
    werase(win);
}

void Window::refreshWin() {
    wrefresh(win);
}
