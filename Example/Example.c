#include "../Class.h"
#include "Example.h"

#include <stdio.h>


implement(Example);


Private(Example) {
    int attribute;
    void (*method)(Example *this);
};

PrivateStatic(Example) {
    int attribute;
};


__constructor__(Example)(int public, int private) {
    __construct__(Example);

    if (__constructing_static__) {
        this->static_->private->attribute = 0;
    }

    this->attribute = public;
    this->private->attribute = private;

    return this;
}

__destructor__(Example)(Example *this) {
    __destruct__(this);
}


void public_method(Example *this) {
    printf("- Public  Attribute: %d\n", this->attribute);

    call(this, private->method);
    call(this->static_, method);
}

void private_method(Example *this) {
    printf("- Private Attribute: %d\n", this->private->attribute);
}

void static_method(Static(Example) *cls) {
    printf("- Static  Attribute: %d\n", cls->private->attribute);
}


__binder__(Example)(Example *this) {
    if (__constructing_static__) {
        this->static_->method = static_method;
    }

    this->method = public_method;
    this->private->method = private_method;
}
