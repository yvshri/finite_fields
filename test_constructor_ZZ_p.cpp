// #include "ZZ_p12.hxx"
// #include "ZZ_p6.hxx"
// #include "ZZ_p2.hxx"
#include "ZZ_p.hxx"
using namespace std;

mpz_t ZZ_p::z;
mpz_t ZZ_p::_mod;
ZZ_p ZZ_p::_zero;
ZZ_p ZZ_p::_qnr;
ZZ_p ZZ_p::_unity;

int main(){
	long prime;
	prime = 7;
	mpz_t seven;
	mpz_init_set_ui(seven, 7);
	ZZ_p::init(seven);
	mpz_t three, five;
	mpz_init_set_ui(three, 3);
	mpz_init_set_ui(five, 5);
	ZZ_p a, b(three);
	const ZZ_p m(ZZ_p::unity());
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
	ZZ_p c(a);
	a = five;
	ZZ_p d(a);
	cout << "a : " << a << endl;
	cout << "d : " << d << endl;
	d = b;
	d = sqr(a);
	cout << "d : " << d << endl;
	power(d, a, three);
	cout << "d : 3" << endl;
	d = -a;
	cout << "-d : " << d << endl;
}