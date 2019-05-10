#include <configuration.h>
#include "Menu.h"
#include <Arduino.h>
#include <menu/MenuPoint.h>
#include <iostream>

void Menu::addEntry(MenuPoint *p) {
    p->setParent(this);
    menuPoints.push_back(p);
}

Menu::Menu() {
    selected = 0;
}

void Menu::draw(Display *display) {
    if (currentMenu != 0) {
        currentMenu->draw(display);
    } else {
        int startY = 0;
        int endY = 4;
        while (selected > endY || endY == menuPoints.size() - 2) {
            startY++;
            endY++;
        }
        int y = 0;
        for (int i = startY; i <= endY; i++) {
            display->string(2, y * FONT_SIZE, menuPoints[i]->getName());
            if (i == selected) {
                display->rect(0, y * FONT_SIZE + 1, 320, FONT_SIZE);
            }
            y++;
        }
    }
}

void Menu::processInput(Joystick *joystick) {
    if (currentMenu != 0) {
        currentMenu->processInput(joystick);
    } else {
        if(joystick->pressed()){
            std::cout << "Pressed"<<std::endl;
            history.push_back(menuPoints[selected]);
            currentMenu = menuPoints[selected];
        }else{
            selected += joystick->getScrollY();
            selected = selected < 0 ? 0 : (selected > menuPoints.size() - 1 ? menuPoints.size() - 1 : selected);
        }
    }
}

void Menu::back() {
    if (history.size() > 1) {
        history.pop_back();
        currentMenu = history[history.size() - 1];
    }
}
