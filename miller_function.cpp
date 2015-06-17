#include "point_ZZ_p.hxx"
#include "point_ZZ_p2.hxx"

using namespace std;

void getMillerFunction(ZZ_p12& f_, const PointZZ_p p_, const PointZZ_p2 q_, const ZZ_p& r_){
	std::vector<bool> r_bin;
	r_bin = r_.decToBin();
	PointZZ_p t;
	ZZ_p12 line, f;
	t = p_;
	f = ZZ_p12::unity();
	long long int i, deg;
	deg = r_.size();
	for (i = deg - 2; i >= 0; --i){
		t = doublePointAndCalcTangent(line, t, q_);
		f = sqrMillerFunction(f);
		f = f * line;
		if(r_.at(i) == 1 && i != 0){
			t = pointAdditionAndLineThroughPoints(line, t, p_, q_);
			f = f * line;
		}
	}
}