#include <utility>

//
// Created by teeeb on 2019-05-21.
//

#pragma once

#include "MenuPoint.h"

class MenuList : public MenuPoint{
private:
    std::vector<MenuPoint *> menupoints;
    int selected = -1;
    MenuPoint *active = 0;

public:
    explicit MenuList(String name) : MenuPoint(std::move(name)) {}
    void addEntry(MenuPoint *p);
    void back();
};