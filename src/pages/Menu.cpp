#include "pages/Menu.h"

#include <cmath>
#include <utility>
#include "Display.h"

Menu::Menu(Display *display, Joystick *input, String name, int pageCount) : Page(display, input, std::move(name)),
                                                                            mPageCount(pageCount) {
    mPages = new Page *[pageCount];
    for (int i = 0; i < mPageCount; ++i) {
        mPages[i] = nullptr;
    }
}

void Menu::update() {
    Page::update();

    int start = isDown ? max(currentItem - 2, 0) : max(currentItem - 1, 0);
    mDisplay->drawVerticalLine(5, HEADER_SIZE + 1, DISPLAY_HEIGHT - HEADER_SIZE - 2);
    float dSize = (float)(DISPLAY_HEIGHT - HEADER_SIZE - 2.0);
    float size = dSize / (float)mPageCount;
    float currProgress = dSize * ((float)currentItem/(float)mPageCount);

    mDisplay->rect(2, (int)(currProgress)+1, 3, std::floor(size));

    for (int i = start, j = 0; i < min(start + 4, mPageCount); ++i, j++) {
        if (currentItem == i)
            mDisplay->rect(10, j * FONT_SIZE + 3, 210, 10);
        if (mPages[i] != nullptr) {
            mDisplay->string(20, j * FONT_SIZE + 1, mPages[i]->getName());
        } else {
            mDisplay->string(20, j * FONT_SIZE + 1, "ITEMNOTFOUND");
        }
    }

    if (mInput->y() < 0) {
        currentItem--;
        isDown = false;
    }
    if (mInput->y() > 0) {
        currentItem++;
        isDown = true;
    }

    if (currentItem < 0) currentItem = 0;
    if (currentItem >= mPageCount) currentItem = mPageCount - 1;
}

void Menu::setItem(int index, Page *page) {
    if (mPageCount > index && index >= 0) {
        mPages[index] = page;
        page->setParent(this);
    }
}
