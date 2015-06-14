/**************************************************************************\
Author:Yash Shrivastava
MODULE: ZZ_p6

SUMMARY:

The class ZZ_p6 is used to represent quadratic extension field. d

\**************************************************************************/
#ifndef __ZZ_P6_HXX // Control inclusion of header files
#define __ZZ_P6_HXX

#include "ZZ_p2.hxx"

class ZZ_p6
{
public:
	ZZ_p6(ZZ_p2 a_1_ = ZZ_p2::zero(), ZZ_p2 a_2_ = ZZ_p2::zero(), ZZ_p2 a_3_ = ZZ_p2::zero());
	ZZ_p6(const ZZ_p6&);
	explicit ZZ_p6(const ZZ_p2&);
	// explicit ZZ_p2(const mpz_t& a);
	// explicit ZZ_p2(long a);
	~ZZ_p6();

	ZZ_p6& operator=(const ZZ_p6& a); // assignment
    ZZ_p6& operator=(const ZZ_p2& a); // assignment
    // ZZ_p2& operator=(const mpz_t& a); // assignment
    // ZZ_p2& operator=(long a); // assignment


	friend ZZ_p6 operator+(const ZZ_p6& a, const ZZ_p6& b);
    friend ZZ_p6& operator+=(ZZ_p6& x, const ZZ_p6& b);
    // friend void add(ZZ_p& x, const ZZ_p& a, const ZZ_p& b); // x = a + b

   
   	friend ZZ_p6 operator*(const ZZ_p6& a, const ZZ_p6& b);
    friend ZZ_p6& operator*=(ZZ_p6& x, const ZZ_p6& b);
    // friend void mul(ZZ_p& x, const ZZ_p& a, const ZZ_p& b); // x = a * b
	friend ZZ_p6 operator*(const ZZ_p6& a, const ZZ_p2& b);
    friend ZZ_p6& operator*=(ZZ_p6& x, const ZZ_p2& b);


	static void init(const ZZ_p2&);
    // ZZ_p::init(p) sets the modulus to p (p > 1)

    static const ZZ_p2 qnr();
    static const ZZ_p6& zero();
    // ZZ_p::zero() yields a read-only reference to zero
  
    static const ZZ_p6& unity();
    // ZZ_p::zero() yields a read-only reference to unity
    friend ostream& operator<<(ostream& s, const ZZ_p6& x);
    // friend istream& operator>>(istream& s, ZZ_p6& x);

    ZZ_p2 getFirst() const;
    ZZ_p2 getSecond() const;
    ZZ_p2 getThird() const;

    void setFirst(const ZZ_p2&);
    void setSecond(const ZZ_p2&);
    void setThird(const ZZ_p2&);

    friend void setToUnity(ZZ_p6&);
    friend void setToZero(ZZ_p6&);

    static ZZ_p6 _qnr;
    static ZZ_p6 _zero, _unity;
private:
	ZZ_p2 _a_1, _a_2, _a_3;
};

#include "ZZ_p6.inl" // Methods are implemented here
#endif // __ZZ_P6_HXX