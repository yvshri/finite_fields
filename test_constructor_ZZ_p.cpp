// #include "ZZ_p12.hxx"
// #include "ZZ_p6.hxx"
// #include "ZZ_p2.hxx"
#include "ZZ_p.hxx"
using namespace std;

// mpz_t ZZ_p::_mod;
// ZZ_p ZZ_p::_zero;
// ZZ_p ZZ_p::_unity;

int main(){
	long prime;
	prime = 7;
	ZZ_p::init(7);
	mpz_t three, five;
	mpz_init_set_ui(three, 3);
	ZZ_p a, b(three);
	const ZZ_p m(ZZ_p::unity());
	cout << "a : " << a << endl;
	cout << "b : " << b << endl;
	ZZ_p c(a);
	a =  three;
	ZZ_p d(a);
	cout << "a : " << a << endl;
	cout << "d : " << d << endl;
	d = b;
	d = sqr(a);
	cout << "d : " << d << endl;
}