#pragma once

#include <Display.h>
#include "../Page/PageInterface.h"

struct Drawable {
    int x = 0, y = 0;
    int w = 0, h = 0;
    bool active = false;
    PageInterface *pageContent;
    Drawable(int xcoord, int ycoord) : x(xcoord), y(ycoord), pageContent(nullptr), active(false) {}

    virtual void _draw(Display *display, int x, int y) {}

};
