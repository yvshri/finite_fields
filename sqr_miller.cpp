#include "ZZ_p12.hxx"

void sqrMillerFunction(ZZ_p12& output_func_, const ZZ_p12& input_func_){
	ZZ_p6 v, f[2];
	v = f[0] * f[1];
	output_func_.setFirst((f[0] + f[1]) * (f[0] + ZZ_p6::qnr() * f[1]) - v - ZZ_p6::qnr() * v);
	output_func_.setSecond(v + v);
}