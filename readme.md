# OOP with C++ (and more)

## Week 1

_Incrementally_ from small (tiny) programs to not-so-small programs

- Simple tooling
  - From IDE Code::Blocks, Dev, Visual Studio, ...
  - to simple tools Atom, g++, make
- Organizing project directory: We will work with projects with many files
  - From:
```
  hello.cpp a.out
```
  - To:
```
  src/hello.cpp      // folder for production code
  bin/hello          // folder for executables
  test/              // folder for test code
  obj/               // folder for object code
  makefile
  readme.md // project info
```
  - makefile objectives:
    - maintaining project structure
    - enabling recompilation when dependent files changes
    - actions:
      - compile
      - link
      - cleanup
      - statistics
  - jenkins/gitlab/googletest
- Reading and writing [htsi](http://htsicpp.blogspot.tw/):
  - [Introducing "How to solve it: CPP"](http://htsicpp.blogspot.tw/2014/08/introducing-how-to-solve-it-cpp.html)
  - [Inner product, round 1](http://htsicpp.blogspot.tw/2014/08/inner-product-round-1.html)
  - [Inner product, round 2: unit tests and basic exception](http://htsicpp.blogspot.tw/2014/08/inner-product-round-2-unit-tests-and.html)
    - why assert from assert.h is not good: forced exit if failed

## Week 2:
