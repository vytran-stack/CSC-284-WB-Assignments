
#include <curses.h>
#include "ChatClientUI.h"

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    if (has_colors()) {
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLUE);
        init_pair(2, COLOR_YELLOW, COLOR_BLACK);
        init_pair(3, COLOR_CYAN, COLOR_BLACK);
    }

    ChatClientUI ui;
    ui.run();

    endwin();
    return 0;
}
