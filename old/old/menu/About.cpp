#include "menu/About.h"
#include "menu/MenuPoint.h"
#include "configuration.h"

About::About() : MenuPoint("About") {

}

void About::draw(Display *display) {
    display->string(2, 0, String(NAME) + String(VERSION));
    display->string(2, FONT_SIZE, "Developed by: Tibor Talosi");
    display->string(2, 2 * FONT_SIZE, "http://github.com/teeebor/espboard");
    display->string(2, 3 * FONT_SIZE, "Licence: MIT");
    display->string(280, 5 * FONT_SIZE, "BACK");
    display->rect(0, 5 * FONT_SIZE + 1, 230, FONT_SIZE);
}

void About::processInput(Joystick *joystick) {
    if(joystick->pressed()){
        parent->back();
    }
}
