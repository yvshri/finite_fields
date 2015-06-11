#include <iostream>
#include <gmpxx.h>

using namespace std;

int main(){
	mpz_t g, s, t, a, b, prod;
	mpz_inits(g, s, t, a, b, prod, NULL);
	cin >> a;
	cin >> b;
	mpz_gcdext(g, s, t, a, b);
	cout << "g : " << g << endl;
	cout << "s : " << s << endl;
	cout << "t : " << t << endl;
	mpz_mul(prod, a, s);
	mpz_mod(t, s, b);
	cout << t << endl;
	mpz_clears(g, s, t, a, b, prod, NULL);
}