#include "ZZ_p12.hxx"
#ifndef __POINT_ZZ_P_HXX // Control inclusion of header files
#define __POINT_ZZ_P_HXX
class PointZZ_p2;
class PointZZ_p{
public:
	PointZZ_p(ZZ_p = ZZ_p::zero(), ZZ_p = ZZ_p::zero(), ZZ_p = ZZ_p::unity());
	PointZZ_p(const PointZZ_p&);
	~PointZZ_p();

	PointZZ_p& operator=(const PointZZ_p&);


	friend PointZZ_p doublePointAndCalcTangent(ZZ_p12&, const PointZZ_p&, const PointZZ_p2&);
	friend PointZZ_p pointAdditionAndLineThroughPoints(ZZ_p12&, const PointZZ_p&, const PointZZ_p&, const PointZZ_p2&);

	//Getter Setter
	ZZ_p getXAffine() const;
	ZZ_p getYAffine() const;

	//Sets Z to 1 and converts the other coordinates affine
	void setXAffine(const ZZ_p& x_);
	void setYAffine(const ZZ_p& y_);

	ZZ_p getXJacobian() const;
	ZZ_p getYJacobian() const;
	ZZ_p getZJacobian() const;

	void setXJacobian(const ZZ_p& x_);
	void setYJacobian(const ZZ_p& y_);
	void setZJacobian(const ZZ_p& z_);

private:
	ZZ_p _x, _y, _z;
};

#include "point_ZZ_p.inl" // Methods are implemented here
#endif // __POINT_ZZ_P_HXX