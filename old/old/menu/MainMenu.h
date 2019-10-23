#include <utility>

//
// Created by teeeb on 2019-05-21.
//

#pragma once

#include "MenuList.h"

class MainMenu : public MenuList{
public:
    explicit MainMenu(String name) : MenuList(std::move(name)) {}

    void draw(Display *display) override;

    void processInput(Joystick *joystick) override;

};