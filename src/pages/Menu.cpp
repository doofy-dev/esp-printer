#include "pages/Menu.h"

#include <utility>
#include "Display.h"

Menu::Menu(Display *display, Joystick *input, String name, int pageCount) : Page(display, input, std::move(name)), mPageCount(pageCount) {
    mPages = new Page *[pageCount];
}

void Menu::update() {
    Page::update();
    mDisplay->string(10, 10, "ADASDASDDAS");
}

void Menu::setItem(int index, Page *page) {
    if (mPageCount < index && index >= 0) {
        mPages[index] = page;
        page->setParent(this);
    }
}
