
#include "RoomList.h"

RoomList::RoomList(int h, int w, int y, int x)
    : Window(h, w, y, x), selected(0) {}

void RoomList::setRooms(const std::vector<std::string>& list) {
    rooms = list;
}

void RoomList::moveUp() {
    if (selected > 0) selected--;
}

void RoomList::moveDown() {
    if (selected < rooms.size() - 1) selected++;
}

std::string RoomList::getSelectedRoom() {
    return rooms[selected];
}

void RoomList::draw() {
    clearContent();
    drawBorder();

    for (int i = 0; i < rooms.size(); i++) {
        if (i == selected)
            wattron(win, A_BOLD | COLOR_PAIR(2));

        mvwprintw(win, i + 1, 2, "%s", rooms[i].c_str());

        if (i == selected)
            wattroff(win, A_BOLD | COLOR_PAIR(2));
    }

    refreshWin();
}
