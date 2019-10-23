#pragma once

#include "PageInterface.h"
#include "../UI/Text.h"

class MainPage : public PageInterface {
public:
    MainPage() : PageInterface() {
        title = new Text("Main menu");
        //
//        childs = new PageInterface[3]{};
    }
};