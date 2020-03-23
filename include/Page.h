#pragma once

#include <WString.h>
#include "IClass.h"
#include "Joystick.h"

class Display;
class Page: public IClass{
protected:
    Display *mDisplay;
    Joystick *mInput;
    String mName;
    Page *child{};
    Page *parent{};
    bool disableBackButton = false;
public:
    Page(Display *display, Joystick *input, String name);
    void setChild(Page *p);
    void setParent(Page *p);
    String getName();
    bool canGoBack();
    void update() override;
};