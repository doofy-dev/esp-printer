#include "Page.h"

#include <utility>
#include "Display.h"

Page::Page(Display *display, Joystick *input, String name) : mDisplay(display), mInput(input), mName(std::move(name)) {
    if(mDisplay->currentPage() == nullptr){
        mDisplay->setPage(this);
    }
}

void Page::setChild(Page *p) {
    p->parent = this;
    child = p;
}

void Page::update() {
    IClass::update();
    if (mInput->dX() < 0 && parent != nullptr) {
        mDisplay->setPage(parent);
    }
}

void Page::setParent(Page *p) {
    parent = p;
}

String Page::getName() {
    return mName;
}

bool Page::canGoBack() {
    return parent != nullptr && !disableBackButton;
}
