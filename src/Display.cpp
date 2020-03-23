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
    display->fillRect(0,0, 200, HEADER_SIZE);
    display->setTextAlignment(TEXT_ALIGN_RIGHT);
    display->drawString(120, 0, curretnPageName);
    display->setTextAlignment(TEXT_ALIGN_LEFT);
    if(mCurrentPage->canGoBack()){
        display->drawString(0,0, "< Back");
    }
    display->display();
    mCurrentPage->lateUpdate();
}

void Display::string(int x, int y, String data) {
    display->drawString(x, y+HEADER_SIZE, std::move(data));
}

void Display::rect(int x, int y, int width, int height) {
    display->fillRect(x, y+HEADER_SIZE, width, height);
}

void Display::setPage(Page *p) {
    mCurrentPage = p;
    curretnPageName = mCurrentPage->getName();
}

Page *Display::currentPage() {
    return mCurrentPage;
}

void Display::lateUpdate() {
    IClass::lateUpdate();
}
void Display::drawVerticalLine(int x, int y, int length){
    display->drawVerticalLine(x, y, length);
}
