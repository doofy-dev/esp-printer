#include "Display.h"

#include <utility>
#include <sstream>
#include <iomanip>
#include "Page.h"

Display::Display() {
    display = new SSD1306Wire(DISPLAY_ADDRESS, DISPLAY_SDA, DISPLAY_SCL);
    display->init();
    display->flipScreenVertically();
    display->setFont(FONT);
    display->setTextAlignment(TEXT_ALIGN);
    display->setColor(TEXT_COLOR);

    ui = new OLEDDisplayUi(display);
}

void Display::beforeUpdate() {
    IClass::beforeUpdate();
    display->display();
}

void Display::update() {
    IClass::update();
    mCurrentPage->beforeUpdate();
    display->clear();
    mCurrentPage->update();
    display->drawString(0, 0, curretnPageName);
    display->display();
    mCurrentPage->lateUpdate();
}

void Display::string(int x, int y, String data) {
    display->drawString(x, y, std::move(data));
}

void Display::rect(int x, int y, int width, int height) {
    display->fillRect(x, y, width, height);
}

void Display::setPage(Page *p) {
    mCurrentPage = p;
    curretnPageName = mCurrentPage->getName();
    int sidePadding = floor((30 - curretnPageName.length()) / 2.0);
    for(int i=0;i<sidePadding;i++){
        curretnPageName = "-"+curretnPageName+"-";
    }

}

Page *Display::currentPage() {
    return mCurrentPage;
}

void Display::lateUpdate() {
    IClass::lateUpdate();
}
