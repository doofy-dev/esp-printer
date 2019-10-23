#pragma once

#include "Drawable.h"

struct Text: public Drawable{
    String text;
    double lastScroll;
    int scrollPos;
    Text(String content);
    Text(int x, int y, String content);
    void _draw(Display *display, int x, int y) override;
};