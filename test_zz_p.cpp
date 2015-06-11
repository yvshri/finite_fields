#include "ZZ_p.hxx"

using namespace std;

int main(){
	mpz_t a, b, c;
	mpz_inits(a, b, c, NULL);
	cin >> a;
	cin >> b;
	cin >> c;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	ZZ_p::init(a);
	ZZ_p d(b), e(c);
	cout << d << endl;
	cout << inv(d) << endl;
}