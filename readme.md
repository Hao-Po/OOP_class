# OOP with C++ (and more)
#### Spring, 2018
#### Prof Y C Cheng
#### Dept of Computer Science and Information Engineering
#### Taipei Tech

## Week 4:

Working on the main program
- operator new and operator new []
- std::getline(std::cin, line)
- _Looking back_

Vector as object

[**Inner product, round 4: refactoring into object**](http://htsicpp.blogspot.tw/2014/09/inner-product-round-4-refactoring-into.html)

## Week 3:

[**How to Solve It**](http://htsicpp.blogspot.tw/2014/08/introducing-how-to-solve-it-cpp.html):
- _Understanding the problem_: by constructing an example
- _Devising a plan_: what we must do to make the example work?
- _Carrying out the plan_: test, code, refactor
- _Looking back_
Our plan for the problem of computing inner product

- Compute inner product
- input/output
  - understanding string
  - understanding iostream objects cin/cout

[**Inner product, round 3: handling I/O**](http://htsicpp.blogspot.tw/2014/08/inner-product-round-3-handling-io.html)

## Week 2:

### reading:

- [Inner product, round 1](http://htsicpp.blogspot.tw/2014/08/inner-product-round-1.html)

- [Inner product, round 2: unit tests and basic exception](http://htsicpp.blogspot.tw/2014/08/inner-product-round-2-unit-tests-and.html)

### C++ language & tool

- When coding in class, I will use the editor [Atom](https://atom.io), which comes with syntax highlighting, code completion to make coding easy. I will also use the plugin [PlatformIO IDE Terminal](https://atom.io/packages/platformio-ide-terminal) so that we can access a terminal to build programs without leaving Atom.

- make and makefile
- exception in c++: why assert from assert.h is not good: forced exit if failed

### problem solving

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
