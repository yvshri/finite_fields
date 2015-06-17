ZZ_p12 sqrMillerFunction(const ZZ_p12& input_func_){
	ZZ_p12 output_func; 
	ZZ_p6 v, f[2];
	f[0] = input_func_.getFirst();
	f[1] = input_func_.getSecond();
	v = f[0] * f[1];
	output_func.setFirst((f[0] + f[1]) * (f[0] + ZZ_p6::qnr() * f[1]) - v - ZZ_p6::qnr() * v);
	output_func.setSecond(v + v);
}