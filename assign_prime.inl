void init(){
	mpz_t z, z4, z3, z2, z1 result;
	mpz_inits(z, z4, z3, z2, z1, result);
	ZZ_p::getZ(z);
	mpz_pow_ui(z4, z, 4);
	mpz_pow_ui(z3, z, 3);
	mpz_pow_ui(z2, z, 2);
	mpz_mul_ui(z4, z4, 36);
	mpz_mul_si(z3, z3, -36);
	mpz_mul_ui(z2, z2, 24);
	mpz_mul_si(z1, z, -6);
	mpz_add(result, z4, z3);
	mpz_add(result, result, z2);
	mpz_add(result, result, z1);
	mpz_add_ui(result, result, 1);
	ZZ_p::init(result);
	ZZ_p::_qnr.setNum(-2);

}