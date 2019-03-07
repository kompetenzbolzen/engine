[![Build Status](https://travis-ci.org/kompetenzbolzen/engine.svg?branch=master)](https://travis-ci.org/kompetenzbolzen/engine)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/9b19f9f7a8d241368f6ee640d824b293)](https://www.codacy.com/app/kompetenzbolzen/engine?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=kompetenzbolzen/engine&amp;utm_campaign=Badge_Grade)
[![CodeFactor](https://www.codefactor.io/repository/github/kompetenzbolzen/engine/badge/master)](https://www.codefactor.io/repository/github/kompetenzbolzen/engine/overview/master)

# engine (the most creative name I could come up with)

engine is a library for displaying ASCII-graphics in a text console. For more information on how to use, consult the documentation (`make doc`) and look at the example programs in `example/`.

## Compiling the library

engine should compile just fine with just the c++ standard librarys. The Makefile is set up for clang, but gcc should also work.
Required Packages:

    clang
    make

`make` creates two folders in `build/`: lib and inc, wich hold the library and the headers respectively. these can then be copied into your projects directory.

Run `make run` to build and run the example program specified by `$TESTSOURCE` in the Makefile. It is not compiled against the library, but just statically linked with the .o-files for easier debugging. The same example-programs can also be linked with the dynamic library by using the Makefile in `example/`.

To build the documentation, install `doxygen` and run `make doc`.

## Compile your project

Compile your program with linkerflags:

    -L/path/to/lib -lengine -lstdc++
