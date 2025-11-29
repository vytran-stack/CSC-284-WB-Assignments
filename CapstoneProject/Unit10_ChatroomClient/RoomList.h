
#pragma once
#include "Window.h"
#include <vector>
#include <string>

class RoomList : public Window {
    std::vector<std::string> rooms;
    int selected;

public:
    RoomList(int h, int w, int y, int x);

    void setRooms(const std::vector<std::string>& list);
    void moveUp();
    void moveDown();
    std::string getSelectedRoom();
    void draw();
};
