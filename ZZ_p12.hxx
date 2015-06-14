/**************************************************************************\
Author:Yash Shrivastava
MODULE: ZZ_p12

SUMMARY:

The class ZZ_p12 is used to represent quadratic extension field. d

\**************************************************************************/
#ifndef __ZZ_P12_HXX // Control inclusion of header files
#define __ZZ_P12_HXX

#include "ZZ_p6.hxx"

class ZZ_p12
{
public:
	ZZ_p12(ZZ_p6 a_1_ = ZZ_p6::zero(), ZZ_p6 a_2_ = ZZ_p6::zero());
	ZZ_p12(const ZZ_p12& a);
	explicit ZZ_p12(const ZZ_p6& a);
	// explicit ZZ_p12(const mpz_t& a);
	// explicit ZZ_p12(long a);
	~ZZ_p12();

	ZZ_p12& operator=(const ZZ_p12& a); // assignment
    ZZ_p12& operator=(const ZZ_p6& a); // assignment
    // ZZ_p12& operator=(const mpz_t& a); // assignment
    // ZZ_p12& operator=(long a); // assignment


	friend ZZ_p12 operator+(const ZZ_p12& a, const ZZ_p12& b);
    friend ZZ_p12& operator+=(ZZ_p12& x, const ZZ_p12& b);
    // friend void add(ZZ_p6& x, const ZZ_p6& a, const ZZ_p6& b); // x = a + b
    friend ZZ_p12 operator-(const ZZ_p12& a, const ZZ_p12& b);
    friend ZZ_p12& operator-=(ZZ_p12& x, const ZZ_p12& b);
   
   	friend ZZ_p12 operator*(const ZZ_p12& a, const ZZ_p12& b);
    friend ZZ_p12& operator*=(ZZ_p12& x, const ZZ_p12& b);
    // friend void mul(ZZ_p6& x, const ZZ_p6& a, const ZZ_p6& b); // x = a * b
	friend ZZ_p12 operator*(const ZZ_p12& a, const ZZ_p6& b);
    friend ZZ_p12& operator*=(ZZ_p12& x, const ZZ_p6& b);


	static void init();
    // ZZ_p6::init(p) sets the modulus to p (p > 1)

    static const ZZ_p12& zero();
    // ZZ_p6::zero() yields a read-only reference to zero
  
    static const ZZ_p12& unity();
    // ZZ_p6::zero() yields a read-only reference to unity
    friend ostream& operator<<(ostream& s, const ZZ_p12& x);
    // friend istream& operator>>(istream& s, ZZ_p6& x);

    ZZ_p6 getFirst() const;
    ZZ_p6 getSecond() const;

    void setFirst(const ZZ_p6&);
    void setSecond(const ZZ_p6&);

    friend void setToUnity(ZZ_p12&);
    friend void setToZero(ZZ_p12&);

    static ZZ_p12 _zero, _unity;
private:
	ZZ_p6 _a_1, _a_2;
};

#include "ZZ_p12.inl" // Methods are implemented here
#endif // __ZZ_P12_HXX