#pragma once
#include "../Class.h"


class(Example);
__constructor__(Example)(int public, int private);


Public(Example) {
    __Components__(Example);

    int attribute;
    void (*method)(Example *this);
};

Static(Example) {
    __StaticComponents__(Example);

    void (*method)(Static(Example) *cls);
};
