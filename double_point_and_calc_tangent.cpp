#include "point_ZZ_p2.hxx"
#include "point_ZZ_p.hxx"

PointZZ_p doublePointAndCalcTangent(ZZ_p12& l_tangent_, const PointZZ_p& input_, const PointZZ_p2& q_){
	PointZZ_p output;
	ZZ_p x_out, y_out, z_out, x_in, y_in, z_in, t[7];
	const ZZ_p two(ZZ_p::unity() + ZZ_p::unity());
	ZZ_p2 l[3];
	ZZ_p6 a[2];
	x_in = input_.getXJacobian();
	y_in = input_.getYJacobian();
	z_in = input_.getZJacobian();

	//1
	t[0] = sqr(x_in);
	t[1] = sqr(y_in);
	t[2] = y_in * z_in;

	//2
	t[3] = sqr(t[0]);
	t[4] = x_in * t[1];
	t[5] = sqr(t[1]);

	//3
	t[4] = two * t[4];
	t[6] = two * t[3];
	z_out = two * t[2];

	//4
	t[4] = two * t[4];
	t[6] = two * t[6];
	t[5] = two * t[5];

	//5
	t[3] = t[3] + t[6];
	t[5] = two * t[5];

	//6
	x_out = t[3] - t[2];
	t[5] = two * t[5];

	//7
	t[3] = t[4] - x_out;
	t[7] = t[7] + t[0];

	//8
	t[7] = t[7] * t[3];
	t[4] = sqr(z_in);
	t[4] = x_in * t[0];

	//9
	y_out = t[7] - t[5];
	t[1] = two * t[1];
	t[5] = two * t[2];

	//10
	t[4] = t[4] * t[0];
	t[0] = t[4] * z_out;

	//11
	t[2] = two * t[4];
	t[5] = t[2] + t[5];

	//12
	t[4] = t[4] + t[2];
	l[0].setFirst(t[5] - t[1]);
	l[0].setSecond(ZZ_p::zero());

	//13
	l[1].setFirst(t[4] * q_.getX().getFirst());
	l[1].setSecond(t[4] * q_.getX().getSecond());

	//14
	l[2].setFirst(t[0] * q_.getY().getFirst());
	l[2].setSecond(t[0] * q_.getY().getSecond());

	a[0].setFirst(l[0]);
	a[0].setThird(l[1]);
	a[1].setFirst(l[2]);

	l_tangent_.setFirst(a[0]);
	l_tangent_.setSecond(a[1]);
	output.setXJacobian(x_out);
	output.setYJacobian(x_out);
	output.setZJacobian(z_out);
	return output;
}