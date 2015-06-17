void init(){
	int res;
	//Init z
	mpz_init(ZZ_p::z);
	const char *s = "-6000000000001F2D";
	cout << s << endl;
	res = mpz_set_str(ZZ_p::z, s, 16);
	assert(res == 0);

	//Init prime
	mpz_t z, z4, z3, z2, z1, result;
	mpz_inits(z, z4, z3, z2, z1, result, NULL);
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
	mpz_clears(z, z4, z3, z2, z1, result, NULL);

	//Init ZZ_p::qnr (-2)
	mpz_t two;
	mpz_init_set_si(two, -2);
	ZZ_p::_qnr.setNum(two);

	//Init ZZ_p2::cnr (-1, -1)
	ZZ_p2 cnr(-(ZZ_p::unity()), -(ZZ_p::unity()));
	ZZ_p2::init(cnr);

	//Init ZZ_p6::qnr (0, 1, 0)
	ZZ_p6 qnr(ZZ_p2::zero(), ZZ_p2::unity(), ZZ_p2::zero());
	ZZ_p6::init(qnr);
}