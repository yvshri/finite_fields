

/**************************************************************************\

MODULE: ZZ_p

SUMMARY:

The class ZZ_p is used to represent integers mod p.  The modulus p may
be any positive integer, not necessarily prime.  

Objects of the class ZZ_p are represented as a mpz_t in the range 0..p-1.

An executing program maintains a "current modulus", which is set to p using
ZZ_p::init(p).  The current modulus *must* be initialized before any operations
on ZZ_p's are performed.  The modulus may be changed, and a mechanism is provided
for saving and restoring a modulus (see classes ZZ_pPush and ZZ_pContext below).


\**************************************************************************/
#ifndef __ZZ_P_HXX // Control inclusion of header files
#define __ZZ_P_HXX
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <gmp.h>

using namespace std;
class ZZ_p {
public:
    /**************************************************************************\

                                  CONSTRUCTORS

    \**************************************************************************/
    ZZ_p(); // initialize to 0
    ZZ_p(const ZZ_p& a); // copy constructor
    explicit ZZ_p(mpz_t);
    // explicit ZZ_p(const long a);  // promotion constructor

    ~ZZ_p(); // destructor

    ZZ_p& operator=(const ZZ_p& a); // assignment
    ZZ_p& operator=(mpz_t a); // assignment
    // ZZ_p& operator=(const long);

    static void init(mpz_t p_);
    static void init(const long p_);
    // ZZ_p::init(p) sets the modulus to p (p > 1)
    static void initConstants();

    static void getModulus(mpz_t);
    // ZZ_p::modulus() yields read-only reference to the current
    // modulus

    static const ZZ_p& zero();
    // ZZ_p::zero() yields a read-only reference to zero
  
    static const ZZ_p& unity();
    // ZZ_p::zero() yields a read-only reference to unity
    
    /**************************************************************************\

                                  COMPARISON

    \**************************************************************************/

    friend long operator==(const ZZ_p& a, const ZZ_p& b);
    friend long operator!=(const ZZ_p& a, const ZZ_p& b);

    // PROMOTIONS: the comparison operators provide promotions
    // from long to ZZ_p on (a, b)

    friend long IsZero(const ZZ_p& a);  // test for 0
    friend long IsOne(const ZZ_p& a);  // test for 1

    

    /**************************************************************************\

                                  ADDITION

    \**************************************************************************/
    friend ZZ_p operator+(const ZZ_p& a, const ZZ_p& b);
    friend ZZ_p operator-(const ZZ_p& a, const ZZ_p& b);
    friend ZZ_p operator-(const ZZ_p& a); // unary -

    friend ZZ_p& operator+=(ZZ_p& x, const ZZ_p& b);
    friend ZZ_p& operator+=(ZZ_p& x, long b);

    friend ZZ_p& operator-=(ZZ_p& x, const ZZ_p& b);
    friend ZZ_p& operator-=(ZZ_p& x, long b);

    friend ZZ_p operator++(ZZ_p& x);  // prefix
    friend ZZ_p operator++(ZZ_p& x, int);  // postfix

    friend ZZ_p operator--(ZZ_p& x);  // prefix
    friend ZZ_p operator--(ZZ_p& x, int);  // postfix

    // procedural versions:


    friend void add(ZZ_p& x, const ZZ_p& a, const ZZ_p& b); // x = a + b
    friend void sub(ZZ_p& x, const ZZ_p& a, const ZZ_p& b); // x = a - b 
    friend void negate(ZZ_p& x, const ZZ_p& a); // x = -a

    // PROMOTIONS: binary +, - and procedures add, sub provide promotions
    // from long to ZZ_p on (a, b)


    /**************************************************************************\

                                  MULTIPLICATION

    \**************************************************************************/
    friend ZZ_p operator*(const ZZ_p& a, const ZZ_p& b);

    friend ZZ_p& operator*=(ZZ_p& x, const ZZ_p& b);
    friend ZZ_p& operator*=(ZZ_p& x, long b);

    // procedural versions:


    friend void mul(ZZ_p& x, const ZZ_p& a, const ZZ_p& b); // x = a * b

    friend void sqr(ZZ_p& x, const ZZ_p& a); // x = a^2
    friend ZZ_p sqr(const ZZ_p& a); // x = a^2

    // PROMOTIONS: operator * and procedure mul provide promotions 
    // from long to ZZ_p on (a, b)

    /**************************************************************************\

                                  DIVISION

    \**************************************************************************/


    // operator notation:

    friend ZZ_p operator/(const ZZ_p& a, const ZZ_p& b);

    friend ZZ_p& operator/=(ZZ_p& x, const ZZ_p& b);
    friend ZZ_p& operator/=(ZZ_p& x, long b);


    // procedural versions:


    friend void div(ZZ_p& x, const ZZ_p& a, const ZZ_p& b);
    // x = a/b.

    friend void inv(ZZ_p& x, const ZZ_p& a); // x = 1/a
    friend ZZ_p inv(const ZZ_p& a); 


    // PROMOTIONS: operator / and procedure div provide promotions
    // from long to ZZ_p on (a, b)


    /**************************************************************************\

                                    Input/Output

    \**************************************************************************/
    friend ostream& operator<<(ostream&, const ZZ_p&);
    // friend istream& operator>>(istream&, ZZ_p&);


    // ostream& operator<<(ostream& s, const ZZ_p& a);

    // istream& operator>>(istream& s, ZZ_p& x);

    /**************************************************************************\

                                   Miscellany

    \**************************************************************************/
    friend void setToZero(ZZ_p& x); // x = 0
    friend void setToUnity(ZZ_p& x); // x = 1
    friend void swap(ZZ_p& x, ZZ_p& y);
    // swap x and y (done by "pointer swapping", if possible).

    void swap(ZZ_p& x);
    // swap member function

    //Getter setter
    void getNum(mpz_t) const;
    void setNum(mpz_t);
    static mpz_t _mod;
    static ZZ_p _zero, _unity;
private:
    mpz_t _num; 
    
};


/**************************************************************************\

                               Miscellany

\**************************************************************************/
// static long ModulusSize();
// //  ZZ_p::ModulusSize() returns ZZ_p::modulus().size()






/**************************************************************************\

                      Access to representation

\**************************************************************************/
/*TODO*/

// mpz_t rep(const ZZ_p& a); 
// read-only access to representation of a

/****** Example: ********  

   mpz_t x;
   ZZ_p a;

   x = rep(a);

*************************/


/**************************************************************************\

                            Exponentiation

\**************************************************************************/
/*TODO*/


// void power(ZZ_p& x, const ZZ_p& a, mpz_t e); // x = a^e (e may be negative)
// ZZ_p power(const ZZ_p& a, mpz_t e); // functional variants

// void power(ZZ_p& x, const ZZ_p& a, long e); 
// ZZ_p power(ZZ_p& x, const ZZ_p& a, long e); 



/**************************************************************************\

                               Random Elements

\**************************************************************************/
/*TODO*/


// void random(ZZ_p& x);
// ZZ_p random_ZZ_p();
// // x = random element in ZZ_p.  


/**************************************************************************\

                       Modulus Switching 


A class ZZ_pPush is provided for "backing up" the current modulus
and installing a new one.

Here is what you do to save the current modulus, temporarily
set it to p, and automatically restore it:

   { 
      ZZ_pPush push(p); 

      ...

   }

The constructor for push will save the current modulus, and install p as the
current modulus.  The destructor for push will restore the old modulus when the
scope enclosing it exits.  This is the so-called RAII (resource acquisition is
initialization) paradigm.

You could also do the following:

   {
      ZZ_pPush push; // just backup current modulus

        ...

      ZZ_p::init(p1); // install p1 

        ...

      ZZ_p::init(p2); // install p2

      // reinstall original modulus as close of scope
   }

      
The ZZ_pPush interface is good for implementing simple stack-like
modulus "context switching".  For more general context switching,
see ZZ_pContext below.  There is also an older ZZ_pBak class
that may also be useful.

..........................................................................

It is critical that ZZ_p objects created under one ZZ_p modulus are not used in
any non-trivial way "out of context", i.e., under a different (or undefined)
ZZ_p modulus.  However, for ease-of-use, some operations may be safely
performed out of context.  These safe operations include: the default and copy
constructor, the destructor, and the assignment operator.  In addition is is
generally safe to read any ZZ_p object out of context (i.e., printing it out, or
fetching its underlying representive using the rep() function).

Any unsafe uses out of context are not in general checked, and may 
lead to unpredictable behavior.


NOTE: the implementation of Vec<ZZ_p> is specialized to manage memory more
efficiently than in the default implementation of Vec<T>.  Specifically,
contiguous elements in a Vec<ZZ_p> are allocated in a contiguous region of
memory.  This reduces the number of calls to the memory allocator, and --- more
significantly --- leads to greater locality of reference.  A consequence of
this implementation is that any calls to SetLength on a Vec<ZZ_p> object will
need to use information about the current modulus, and so such calls should
only be done "in context".  That said, it is still safe to construct a
Vec<ZZ_p> using the default or copy contructor, and to assign or append one
Vec<ZZ_p> to another "out of context".

\**************************************************************************/



// A convenient interface for common cases:

// class ZZ_pPush {

// public:
// ZZ_pPush();  // backup current modulus
// explicit ZZ_pPush(mpz_t p); 
// explicit ZZ_pPush(const ZZ_pContext& context); 
//   // backup current modulus and install the given one

// private:
// ZZ_pPush(const ZZ_pPush&); // disabled
// void operator=(const ZZ_pPush&); // disabled

// };



// more general context switching:
// A ZZ_pContext object has a modulus q (possibly "null")

// class ZZ_pContext {


// public:

// ZZ_pContext(); // q = "null"

// explicit ZZ_pContext(mpz_t p);  // q = p

// void save(); // q = CurrentModulus
// void restore() const; // CurrentModulus = q

// ZZ_pContext(const ZZ_pContext&);  // copy
// ZZ_pContext& operator=(const ZZ_pContext&); // assignment
// ~ZZ_pContext(); // destructor


// };


// An older interface:
// To describe this logic, think of a ZZ_pBak object
// of having two components: a modulus q (possibly "null") and 
// an "auto-restore bit" b.

// class ZZ_pBak {
// public:


//    ZZ_pBak();  // q = "null", b = 0

//    ~ZZ_pBak();  // if (b) CurrentModulus = q

//    void save();  // q = CurrentModulus, b = 1 
//    void restore();  // CurrentModulus = q, b = 0


// private:
//    ZZ_pBak(const ZZ_pBak&);  // copy disabled
//    void operator=(const ZZ_pBak&);  // assignment disabled
// };






/**************************************************************************\

                               Miscellany

\**************************************************************************/



// ZZ_p::ZZ_p(INIT_NO_ALLOC_TYPE);
// // special constructor: invoke as ZZ_p x(INIT_NO_ALLOC);
// // initializes x to 0, but allocates no space (this is now the default)

// ZZ_p::ZZ_p(INIT_ALLOC_TYPE);
// // special constructor: invoke as ZZ_p x(INIT_ALLOC);
// // initializes x to 0, but allocates space


// ZZ_p::allocate();
// // useful in conjunction with the INIT_NO_ALLLOC constructor:
// // x.allocate() will pre-allocate space for x, using the
// // current modulus

#include "ZZ_p.inl" // Methods are implemented here
#endif // __ZZ_P_HXX