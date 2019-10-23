#include <utility>
#include <configuration.h>
#include <UI/Text.h>

Text::Text(String content) : Drawable(0, 0), text(std::move(content)) {
    w = 320;
    lastScroll = millis();
    scrollPos = -1;
    h = FONT_SIZE;
}

Text::Text(int x, int y, String content) : Drawable(x, y), text(std::move(content)) {
    w = 320;
    lastScroll = millis();
    scrollPos = -1;
    h = FONT_SIZE;
}

void Text::_draw(Display *display, int x, int y) {
    if (!active) {
        display->drawText(text, x, y);
        scrollPos = -1;
    } else {
        double currentTime = millis();
        int textWidth = display->stringWidth(text);

        if (currentTime - lastScroll > MENU_RESPONSIVENESS_MS && textWidth > w) {
            lastScroll = currentTime;
            scrollPos += 1;
            if (scrollPos + DISPLAY_WIDTH < text.length()) {
                scrollPos = 0;
            }
        }
        String retText = "";
        for (int i = scrollPos; i < text.length(); i++) {
            retText = retText + text[i];
        }
        display->drawText(retText, x, y);


        display->drawRect(x, y, w, h);
    }
}
