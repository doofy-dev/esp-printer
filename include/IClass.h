#pragma once

class IClass {
public:
    virtual void start() {}

    virtual void update() {}

    virtual void lateUpdate() {}

    virtual void beforeUpdate() {}
};