PointZZ_p::PointZZ_p(ZZ_p x_, ZZ_p y_, ZZ_p z_):_x(x_), _y(y_), _z(z_){

}

PointZZ_p::PointZZ_p(const PointZZ_p& p_){
	_x = p_._x;
	_y = p_._y;
	_z = p_._z;
}

PointZZ_p::~PointZZ_p(){

}

PointZZ_p& PointZZ_p::operator=(const PointZZ_p& p_){
	_x = p_._x;
	_y = p_._y;
	_z = p_._z;
	return *this;
}

ZZ_p PointZZ_p::getXAffine() const{
	ZZ_p z_inv;
	inv(z_inv, getZJacobian());
	return _x * z_inv * z_inv;
}
ZZ_p PointZZ_p::getYAffine() const{
	ZZ_p z_inv;
	inv(z_inv, getZJacobian());
	return _y * z_inv * z_inv * z_inv;
}

void PointZZ_p::setXAffine(const ZZ_p& x_){
	ZZ_p z_inv;
	inv(z_inv, getZJacobian());
	_x = x_;
	_y = _y * z_inv * z_inv * z_inv;
	_z = ZZ_p::unity();
}
void PointZZ_p::setYAffine(const ZZ_p& y_){
	ZZ_p z_inv;
	inv(z_inv, getZJacobian());
	_y = y_;
	_x = _x * z_inv * z_inv;
	_z = ZZ_p::unity();
}

ZZ_p PointZZ_p::getXJacobian() const{
	return _x;
}
ZZ_p PointZZ_p::getYJacobian() const{
	return _y;
}
ZZ_p PointZZ_p::getZJacobian() const{
	return _z;
}	

void PointZZ_p::setXJacobian(const ZZ_p& x_){
	_x = x_;
}
void PointZZ_p::setYJacobian(const ZZ_p& y_){
	_y = y_;
}
void PointZZ_p::setZJacobian(const ZZ_p& z_){
	_z = z_;
}