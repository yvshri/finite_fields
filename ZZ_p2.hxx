/**************************************************************************\
Author:Yash Shrivastava
MODULE: ZZ_p2

SUMMARY:

The class ZZ_p2 is used to represent quadratic extension field. d

\**************************************************************************/
#ifndef __ZZ_P2_HXX // Control inclusion of header files
#define __ZZ_P2_HXX

#include "ZZ_p.hxx"

class ZZ_p2
{
public:
	ZZ_p2(ZZ_p a_1_ = ZZ_p(0), ZZ_p a_2_ = ZZ_p(0));
	ZZ_p2(const ZZ_p2& a);
	explicit ZZ_p2(const ZZ_p& a);
	// explicit ZZ_p2(const mpz_t& a);
	// explicit ZZ_p2(long a);
	~ZZ_p2();

	ZZ_p2& operator=(const ZZ_p2& a); // assignment
    ZZ_p2& operator=(const ZZ_p& a); // assignment
    // ZZ_p2& operator=(const mpz_t& a); // assignment
    // ZZ_p2& operator=(long a); // assignment


	friend ZZ_p2 operator+(const ZZ_p2& a, const ZZ_p2& b);
    friend ZZ_p2& operator+=(ZZ_p2& x, const ZZ_p2& b);
    // friend void add(ZZ_p& x, const ZZ_p& a, const ZZ_p& b); // x = a + b

   
   	friend ZZ_p2 operator*(const ZZ_p2& a, const ZZ_p2& b);
    friend ZZ_p2& operator*=(ZZ_p2& x, const ZZ_p2& b);
    // friend void mul(ZZ_p& x, const ZZ_p& a, const ZZ_p& b); // x = a * b
	friend ZZ_p2 operator*(const ZZ_p2& a, const ZZ_p& b);
    friend ZZ_p2& operator*=(ZZ_p2& x, const ZZ_p& b);


	static void init(const ZZ_p& qnr_square);
    // ZZ_p::init(p) sets the modulus to p (p > 1)

    static const ZZ_p qnrSquare();
    
    friend ostream& operator<<(ostream& s, const ZZ_p2& x);
    // friend istream& operator>>(istream& s, ZZ_p& x);


    static ZZ_p _qnr_square;
private:
	ZZ_p _a_1, _a_2;
};

#include "ZZ_p2.inl" // Methods are implemented here
#endif // __ZZ_P2_HXX