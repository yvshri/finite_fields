#include "ZZ_p12.hxx"
#include "point_ZZ_p.hxx"
#include "point_ZZ_p2.hxx"
#include "double_point_and_calc_tangent.inl"
#include "point_addition_and_line_through_points.inl"
#include "sqr_miller.inl"
#include "miller_function.inl"
#include "final_exponentiation.inl"
#include "init.inl"
mpz_t ZZ_p::z;
mpz_t ZZ_p::_mod;
ZZ_p ZZ_p::_zero;
ZZ_p ZZ_p::_unity;
ZZ_p ZZ_p::_qnr;

ZZ_p2 ZZ_p2::_cnr;
ZZ_p2 ZZ_p2::_zero;
ZZ_p2 ZZ_p2::_unity;

ZZ_p6 ZZ_p6::_qnr;
ZZ_p6 ZZ_p6::_zero;
ZZ_p6 ZZ_p6::_unity;

ZZ_p12 ZZ_p12::_zero;
ZZ_p12 ZZ_p12::_unity;



int main(){
	init();
	cout << ZZ_p::qnr() << endl;
	ZZ_p neg;
	neg = -ZZ_p::unity();
	cout << neg << endl;
	cout << ZZ_p2::cnr() << endl;
	cout << ZZ_p6::qnr() << endl;
	return 0;
}