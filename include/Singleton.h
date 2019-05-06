//
// Created by teeeb on 2019-05-05.
//

#pragma once

class Singleton
{
private:
    static Singleton* instance;

protected:
    Singleton();

public:
    static Singleton* getInstance();
};
