PointZZ_p pointAdditionAndLineThroughPoints(ZZ_p12& line_, const PointZZ_p& input_t_, const PointZZ_p& input_p_, const PointZZ_p2& q_){
	PointZZ_p output;
	ZZ_p t[11], x[4], y[4], z[3];
	ZZ_p2 l[3];
	ZZ_p6 a[2];

	x[1] =  input_t_.getXJacobian();
	y[1] = input_t_.getYJacobian();
	z[1] = input_t_.getZJacobian();
	x[2] = input_p_.getXAffine();
	y[2] = input_p_.getYAffine();

	//Check the karatsuba
	//1
	t[0] = y[2]*z[1];
	t[1] = sqr(z[1]);

	//2
	t[0] = t[1] * t[0];
	t[1] = t[1] * x[2];

	//3
	t[4] = t[1] + x[1];
	t[0] = t[0] - y[1];
	t[5] = t[1] - x[1];

	//4
	t[3] = sqr(t[0]);
	z[3] = t[5] * z[1];
	t[7] = sqr(t[5]);
	l[1].setFirst(t[0] * q_.getX().getFirst());
	l[1].setSecond(t[0] * q_.getX().getSecond());

	//5
	t[2] =t[7] * x[1];
	t[4] = t[4] * t[7];
	t[5] = t[5] * t[7];
	t[10] = t[0] * x[2];

	//6
	x[3] = t[3] - t[4];

	//7
	t[2] = t[2] - x[3];
	t[2] = t[2] * t[0];
	t[4] = y[2] * z[3];
	t[5] = t[5] * y[1];
	l[2].setFirst(z[3] * y[0]);
	l[2].setSecond(z[3] * y[1]);

	//9
	y[3] = t[2] - t[5];
	l[0].setFirst(t[10] - t[4]);

	a[0].setFirst(l[0]);
	a[0].setThird(l[1]);
	a[1].setFirst(l[2]);

	line_.setFirst(a[0]);
	line_.setSecond(a[1]);
	output.setXJacobian(x[3]);
	output.setYJacobian(y[3]);
	output.setZJacobian(z[3]);

	return output;
}
