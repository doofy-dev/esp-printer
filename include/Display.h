#pragma once

#include <vector>
#include <OLEDDisplayUi.h>
#include <SSD1306Wire.h>

class Drawable;
class Display{
    int cursorX, cursorY;
    int scrollX, scrollY;
    int contentHeight = 0;
    int contentWidht = 0;
    bool isNav= false;
    std::vector<Drawable *> items;
    std::vector<Drawable *> nav;
    Drawable *active;


    OLEDDisplayUi *ui;
    SSD1306Wire *display;
public:
    Display();
    void resetCursor();
    void findActive();
    void insertItem(Drawable *d);
    void clearItems();
    void draw();
    void drawScrollBar();
    void drawText(String text, int x, int y);
    void drawRect(int x, int y, int w, int h);
    int stringWidth(String text);
};