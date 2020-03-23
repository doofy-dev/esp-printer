#pragma once

#include "../Page.h"

class Menu : public Page {
private:
    int currentItem = 0;
    bool isDown=false;
    Page **mPages;
    int mPageCount;
public:
    Menu(Display *display, Joystick *input, String name, int pageCount);
    virtual void update() override;
    void setItem(int index, Page *page);
};