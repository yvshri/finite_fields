#include "ZZ_p12.hxx"
#ifndef __POINT_ZZ_P2_HXX // Control inclusion of header files
#define __POINT_ZZ_P2_HXX
class PointZZ_p;
class PointZZ_p2{
public:
	PointZZ_p2(ZZ_p2 = ZZ_p2::zero(), ZZ_p2 = ZZ_p2::zero());
	PointZZ_p2(const PointZZ_p2&);
	~PointZZ_p2();

	PointZZ_p2& operator=(const PointZZ_p2&);

	friend void doublePointAndCalcTangent(ZZ_p6&, PointZZ_p&, const PointZZ_p&, const PointZZ_p2&);

	//Getter Setter
	ZZ_p2 getX() const;
	ZZ_p2 getY() const;

	//Sets Z to 1 and converts the other coordinates affine
	void setX(const ZZ_p2& x_);
	void setY(const ZZ_p2& y_);

private:
	ZZ_p2 _x, _y;
};

#include "point_ZZ_p2.inl" // Methods are implemented here
#endif // __POINT_ZZ_P2_HXX