//
// Created by teeeb on 2019-05-13.
//

#include "DisplayString.h"

DisplayString::DisplayString(String data, int width) {
    text = data;
    maxwidth = width;
    lastScroll = millis();
    scrollPos=0;
}

String DisplayString::getText() {
    double currentTime = millis();
    if (currentTime - lastScroll > MENU_RESPONSIVENESS_MS) {
        lastScroll=currentTime;
        scrollPos+=1;
        if(scrollPos+DISPLAY_WIDTH<text.length()){
            scrollPos=0;
        }
    }
    String retText = "";
    for(int i=scrollPos;i<text.length();i++){
        retText = retText+text[i];
    }

    return retText;
}
