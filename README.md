# OOP midterm
#### Spring, 2018
#### 25	April 2018, 1:10 pm – 4:00pm

**Questions:**

The following are examples of a polynomial of a single variable (一元多項式):


    x² − 4x + 7   //polynomial 1
    0             //polynomial 2


The first polynomial has three terms(項): x², − 4x and 7; The second polynomial has one term 0. As can be seen, each term is represented by a pair of numbers: the coefficient (係數) of the variable and the exponent (冪次) of the variable . For example, the term x² is represented by the term (1, 2) because it has coefficient 1 and exponent 2. Similarly, − 4x, and 7 are represented by (-4,1) and (7,0), respectively; and the polynomial 0 has one term represented by (0,0).

Please write **unit tests** in "**test/test_term.h**" and "**test/test_polynomial.h**", and implement two classes, the class "**Term**" in "**src/term.h**" file and the class "**Polynomial**" in "**src/polynomial.h**" file, according to the following requirements.


**Requirement:**

1. **Please push your program to your gitlab account and go to Jenkins to check the execution result.**

2. Please pack your terms into the polynomial in ascending power. For example:


    6x³ - 3x² + 3   <=> { (3, 0), (0, 1), (-3, 2), (6, 3) }

    2x              <=> { (0, 0), (2, 1) }

    4x²             <=> { (0, 0), (0, 1), (4, 2) }


3. For the **destructor**, you need to make sure that **no memory leaks** appear in your program.

4. Please use **deep copy** to write your **copyConstructor**.


**Prototypes of classes and functions:**

    class Term {
        ...
        Term () {...}                                               //( 5%)constructor1
        Term (double coef, int exp) {...}                           //( 5%)constructor2
        double coefficient() const {...}                            //( 5%)get the coefficient
        int exponent() const {...}                                  //( 5%)get the exponent
        bool operator == (Term const & t) const {...}               //( 5%)"equal to" operator
        Term operator * (Term const & t) const {...}                //(10%)"multiply" operator
        bool isZero() const {...}                                   //( 5%)check if it is zero
        ...
    };

    =============================================================================================

    class Polynomial {
        ...
        Polynomial (Term * const ts, int ts_size, int degree) {...} //(10%)constructor
        Polynomial (const Polynomial & p) {...)                     //( 5%)copyConstructor
        ~Polynomial(){...}                                          //( 5%)destructor
        Polynomial operator = (const Polynomial & p) {...}          //(10%)copyAssignment
        Term term(int degree) const {...}                           //( 5%)get a term by degree
        /*If the term is not exist, please also return a term like (0, degree)*/
        int degreeOfPolynomial() const {...}                        //( 5%)get the degree
        void multiplyByTerm(Term t) {...}                           //(10%)multiply by a term
        ...
    };
    Polynomial operator + (const Polynomial & p, const Polynomial & q){...}//(10%)
    /*"addition" operator, please implement it outside the polynomial class*/



**Note:**
1. Make sure your code are writen in the correct file.
2. All parts of the score will be divided into three parts: code(40%), self unit tests(20%), TA's unit tests(40%).
3. You can use this [makefile](https://www.dropbox.com/s/kbr9twdcrpnde80/makefile?dl=0)

**Resources allowed to use**
-  [cplusplus.com](http://www.cplusplus.com/ "cplusplus.com")
- [Prescribed Dictionary](https://dictionary.cambridge.org/zht/%E8%A9%9E%E5%85%B8/%E8%8B%B1%E8%AA%9E-%E6%BC%A2%E8%AA%9E-%E7%B9%81%E9%AB%94/)
- Your own c++ reference book (Don't share with others!).
- Your own homework commit history.

**Attention!! You cannot visit any other website, or you will be considered as cheating.**
