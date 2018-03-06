# OOP with C++ (and more)
<<<<<<< HEAD
#Test
=======

## Week 2:

### Tool

When coding in class, I will use the editor [Atom](https://atom.io), which comes with syntax highlighting, code completion to make coding easy. I will also use the plugin [PlatformIO IDE Terminal](https://atom.io/packages/platformio-ide-terminal) so that we can access a terminal to build programs without leaving Atom.

We are going to solve this problem
- all code together
- separate entry point (main), functions, and tests
- extract tests under gtest

**Problem**. Prompt the user to input two vectors. Compute the inner product (or dot product) of two vectors when it is defined. For example,

    [1, 0] · [1, 1] = 1,
    [1, 1, 0] · [0, 1, 1] = 1, and
    [1,0] · [1,1,0] => undefined.

Prompt the user whether to continue or stop.

More detail see [Inner product, round 1](http://htsicpp.blogspot.tw/2014/08/inner-product-round-1.html)

>>>>>>> 5f5e642afc6292652f2ac2fb0dc5eee7c5a74c6c
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
<<<<<<< HEAD
  - makefile objectives:
    - maintaining project structure
    - enabling recompilation when dependent files changes
    - actions:
      - compile
      - link
      - cleanup
      - statistics
  - jenkins/gitlab/googletest
=======
- makefile objectives:
  - maintaining project structure
  - enabling recompilation when dependent files changes
  - actions:
    - compile
    - link
    - cleanup
    - statistics
- jenkins/gitlab/googletest
>>>>>>> 5f5e642afc6292652f2ac2fb0dc5eee7c5a74c6c
- Reading and writing [htsi](http://htsicpp.blogspot.tw/):
  - [Introducing "How to solve it: CPP"](http://htsicpp.blogspot.tw/2014/08/introducing-how-to-solve-it-cpp.html)
  - [Inner product, round 1](http://htsicpp.blogspot.tw/2014/08/inner-product-round-1.html)
  - [Inner product, round 2: unit tests and basic exception](http://htsicpp.blogspot.tw/2014/08/inner-product-round-2-unit-tests-and.html)
    - why assert from assert.h is not good: forced exit if failed
<<<<<<< HEAD

## Week 2:
=======
>>>>>>> 5f5e642afc6292652f2ac2fb0dc5eee7c5a74c6c
