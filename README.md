# Class

Class is a header-only library for the C language that uses compiler macros, typedefs, structs and function pointers to simulate classes and objects.


## Warning

This library was created for study purposes only and should **not** be used in official projects since it lacks a robust error handling system and has a big memory overhead.


## Features

Classes can be defined with public or private members and support static attributes and methods. There are also macros to facilitate construction, destruction and method calls.

> **Warning:** The static members of a class have a non-standard lifetime. The static instance is initialized once the first object of the class is created and deleted as soon as the reference count for the class instances reaches zero again.


## Errors

The only error this library is capable of handling is if there is not enough memory to instantiate an object, in this case the `new()` macro will return **NULL** and `errno` will be set to **ENOMEM**.


## Dependencies

The [Class.h](https://github.com/pedrolmcastro/class/blob/main/Class.h) file depends only on C standard libraries, but is based on macros and so it can be compiler dependent. The compatibility for the _gcc_ compiler is guaranteed.

- errno.h
- stdlib.h


## Usage

The [Template.c](https://github.com/pedrolmcastro/class/blob/main/Template.c) and [Template.h](https://github.com/pedrolmcastro/class/blob/main/Template.h) files are references to define classes with comments in places where code must be added and the [Example/](https://github.com/pedrolmcastro/class/tree/main/Example) directory provides a complete and simple usage example.
