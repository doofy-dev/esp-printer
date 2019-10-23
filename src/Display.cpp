#include <utility>

#include <utility>

#include <Display.h>
#include <vector>
#include "configuration.h"
#include <UI/Drawable.h>

Display::Display() {
    cursorX = 0;
    cursorY = 0;
    scrollX = 0;
    scrollY = 0;
    isNav = false;
    active = nullptr;
    items = std::vector<Drawable *>();

    display = new SSD1306Wire(DISPLAY_ADDRESS, DISPLAY_SDA, DISPLAY_SCL);
    display->init();
    display->flipScreenVertically();
    display->setFont(FONT);
    display->setTextAlignment(TEXT_ALIGN);
    display->setColor(TEXT_COLOR);

    ui = new OLEDDisplayUi(display);
}

void Display::resetCursor() {
    cursorX = 0;
    cursorY = 0;
    scrollX = 0;
    scrollY = 0;
    isNav = false;
    findActive();
}

void Display::findActive() {
    int posX = cursorX + scrollX;
    int posY = cursorY + scrollY;
    active = nullptr;
    if (!isNav) {
        for (auto item : items) {
            if (item->x == posX && item->y == posY) {
                active = item;
                item->active = true;
            } else {
                item->active = false;
            }
        }
    }
}

void Display::insertItem(Drawable *d) {
    items.push_back(d);
    for (auto item : items) {
        if (item->x + item->w > contentWidht) {
            contentWidht = item->x + item->w;
        }
        if (item->y + item->h > contentHeight) {
            contentHeight = item->y + item->h;
        }
    }
}

void Display::clearItems() {
    items.clear();
    active = nullptr;
}

void Display::draw() {
    display->clear();
    for (auto item : items) {
        int itemTopX = item->x - scrollX;
        int itemTopY = item->y - scrollY;
        int itemBotX = itemTopX + item->w;
        int itemBotY = itemTopY + item->h;
        if ((itemBotX > 0 || itemTopX < DISPLAY_WIDTH) && (itemBotY > 0 || itemTopY < DISPLAY_HEIGHT)) {
            item->_draw(this, itemTopX, itemTopY);
        }
    }
    drawScrollBar();
    display->display();
}

void Display::drawScrollBar() {
    if (contentHeight > DISPLAY_HEIGHT) {
        display->drawVerticalLine(DISPLAY_WIDTH - 5, 0, DISPLAY_HEIGHT);
        double scrollBarHeight = (float) DISPLAY_HEIGHT / contentHeight;
        double scrollbarPos = scrollBarHeight + ((float) DISPLAY_HEIGHT / max(1, scrollY));
        display->drawLine(DISPLAY_WIDTH - 10, (int) round(scrollbarPos), 0,
                          (int) round(scrollbarPos + scrollBarHeight));
    }
}

void Display::drawText(String text, int x, int y) {
    display->drawString(x, y, std::move(text));
}

void Display::drawRect(int x, int y, int w, int h) {
    display->fillRect(x, y, w, h);
}

int Display::stringWidth(String text) {
    return display->getStringWidth(std::move(text));
}

