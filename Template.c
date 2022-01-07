#include "Class.h"
#include "Template.h"


implement(Template);


Private(Template) {
    /* Declare Private Attributes/Methods Here */
};

PrivateStatic(Template) {
    /* Declare Private Static Attributes/Methods Here */
};


__constructor__(Template)(/* Declare Constructor Arguments Here */) {
    __construct__(Template);

    if (__constructing_static__) {
        /* Initialize Static Attributes Here */
    }

    /* Initialize Attributes Here */

    return this;
}

__destructor__(Template)(Template *this) {
    if (__destructing_static__) {
        /* Free Static Attributes Here */
    }

    /* Free Attributes Here */

    __destruct__(this);
}


/* Declare Methods Here */


__binder__(Template)(Template *this) {
    if (__constructing_static__) {
        /* Bind Static Methods Here */
    }

    /* Bind Methods Here */
}
