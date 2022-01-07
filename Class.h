#pragma once
#include <errno.h>
#include <stdlib.h>


/* Method Callers */
#define call(this, method, ...) this->method(this __VA_OPT__(,) __VA_ARGS__)
#define new(cls, ...) __ ## cls ## _constructor__(__VA_ARGS__)
#define delete(this) this->__delete__(this)


/* Magic Methods Signatures */
#define __constructor__(cls) cls *__ ## cls ## _constructor__
#define __destructor__(cls) void __ ## cls ## _destructor__
#define __binder__(cls) inline static void __ ## cls ## _binder__


/* Static Struct Construct/Descruct Checkers */
#define __constructing_static__ __references__ == 1
#define __destructing_static__ __references__ == 1


/* Components Definitions */
#define Public(cls) struct cls
#define Static(cls) struct Static ## cls
#define Private(cls) struct Private ## cls
#define PrivateStatic(cls) struct PrivateStatic ## cls


/* Type Definition */
#define class(cls) typedef Public(cls) cls


#define __Components__(cls)                                         \
    Static(cls) *static_;                                           \
    Private(cls) *private;                                          \
    void (*__delete__)(cls *this);                                  \

#define __StaticComponents__(cls) PrivateStatic(cls) *private


#define implement(cls)                                              \
    /* Declaring Magic Methods */                                   \
    __destructor__(cls)(cls *);                                     \
    __binder__(cls)(cls *);                                         \
    /* Declaring Static Global Variables */                         \
    static size_t __references__ = 0;                               \
    static Static(cls) *__static__ = NULL;                          \


#define __construct__(cls)                                          \
    /* Constructing This Public Struct */                           \
    cls *this = malloc(sizeof(Public(cls)));                        \
    if (this == NULL) {                                             \
        errno = ENOMEM;                                             \
        return NULL;                                                \
    }                                                               \
    /* Constructing This Private Struct */                          \
    this->private = malloc(sizeof(Private(cls)));                   \
    if (this->private == NULL) {                                    \
        free(this);                                                 \
        errno = ENOMEM;                                             \
        return NULL;                                                \
    }                                                               \
    if (__references__ == 0) {                                      \
        /* Constructing Static Public Struct */                     \
        __static__ = malloc(sizeof(Static(cls)));                   \
        if (__static__ == NULL) {                                   \
            free(this);                                             \
            free(this->private);                                    \
            errno = ENOMEM;                                         \
            return NULL;                                            \
        }                                                           \
        /* Constructing Static Private Struct */                    \
        __static__->private = malloc(sizeof(PrivateStatic(cls)));   \
        if (__static__->private == NULL) {                          \
            free(this);                                             \
            free(this->private);                                    \
            free(__static__);                                       \
            errno = ENOMEM;                                         \
            return NULL;                                            \
        }                                                           \
    }                                                               \
    __references__++;                                               \
    this->static_ = __static__;                                     \
    /* Binding Methods */                                           \
    this->__delete__ = __ ## cls ## _destructor__;                  \
    __ ## cls ## _binder__(this);                                   \

#define __destruct__(this)                                          \
    /* Destructing Static Struct */                                 \
    if (__destructing_static__) {                                   \
        free(this->static_->private);                               \
        free(this->static_);                                        \
        __static__ = NULL;                                          \
    }                                                               \
    /* Destructing This Struct */                                   \
    free(this->private);                                            \
    free(this);                                                     \
    __references__--;                                               \

