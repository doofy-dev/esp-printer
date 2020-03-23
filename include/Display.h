#pragma once

#include <Wire.h>

#include <SSD1306Wire.h>
#include <OLEDDisplayUi.h>
#include "configuration.h"
#include "IClass.h"

class Page;

class Display : public IClass {
private:
    OLEDDisplayUi *ui;
    SSD1306Wire *display;
    Page *mCurrentPage{};
    String curretnPageName;
public:
    Display();

    void beforeUpdate() override;
    void lateUpdate() override;

    void setPage(Page *p);

    void update() override;

    Page *currentPage();

    void string(int x, int y, String data);

    void rect(int x, int y, int width, int height);

    void drawVerticalLine(int x, int y, int length);
};