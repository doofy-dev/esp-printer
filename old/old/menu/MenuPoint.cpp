#include "menu/MenuPoint.h"

void MenuPoint::back() {
    if (parent != 0) {
        parent->active = 0;
    }
}

void MenuPoint::draw(Display *display) {
    if (active != 0) {
        active->draw(display);
    } else {
        display->string(2, 0, getName());
        display->rect(0, 0, DISPLAY_WIDTH, FONT_SIZE);

        display->string(2, 0, "Back");
        if (selectOrBack == 2) {
            display->rect(0, DISPLAY_HEIGHT - FONT_SIZE, DISPLAY_WIDTH / 2, FONT_SIZE);
        }

        display->string(DISPLAY_WIDTH / 2 + 2, 0, "Select");
        if (selectOrBack == 1) {
            display->rect(0, DISPLAY_HEIGHT - FONT_SIZE, DISPLAY_WIDTH / 2, FONT_SIZE);
        }

        render(display);
    }
}

void MenuPoint::processInput(Joystick *joystick) {
    if (active != 0) {
        active->processInput(joystick);
    } else {
        if (selectOrBack != 0 || !input(joystick)) {
            selectOrBack = 2 - selectOrBack;
        }
    }
}


