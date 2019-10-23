#pragma once

#include <Joystick.h>
#include <Display.h>
#include "../UI/Text.h"
#include "../UI/Drawable.h"


//This thing is bullshit
class PageInterface {
protected:
    PageInterface **childs;
    int childCount;
    Text *title;
public:
    //the implementation has to set the childs in constructor
    PageInterface() = default;

    //resetting the cursor on activation
    //the main idea is that the display holds the cursor position and current scrolling both vertical and horizontal
    //so the display has to accept bigger values on both axes and manage the scrolling there
    //then the manager only has to deal with proxying the display/input methods
    void activate(Display *display) {
        display->resetCursor();
        int startY = 0;
        for (int i = 0; i < childCount; ++i) {
            childs[i]->title->y = startY;
        }
    }

    //Return false to tell the manager that it does not handled the input
    virtual bool ProcessInput(Joystick *joystick) { return false; }

};