
#pragma once
#include <curses.h>

class Window {
protected:
    WINDOW* win;
    int height, width, startY, startX;

public:
    Window(int h, int w, int y, int x);
    virtual ~Window();

    virtual void drawBorder();
    virtual void clearContent();
    virtual void refreshWin();
    WINDOW* getWin() const { return win; }
};
