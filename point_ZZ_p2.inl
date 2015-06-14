PointZZ_p2::PointZZ_p2(ZZ_p2 x_, ZZ_p2 y_):_x(x_), _y(y_){

}

PointZZ_p2::PointZZ_p2(const PointZZ_p2& p_){
	_x = p_._x;
	_y = p_._y;
}

PointZZ_p2::~PointZZ_p2(){

}

PointZZ_p2& PointZZ_p2::operator=(const PointZZ_p2& p_){
	_x = p_._x;
	_y = p_._y;
	return *this;
}


ZZ_p2 PointZZ_p2::getX() const{
	return _x;
}
ZZ_p2 PointZZ_p2::getY() const{
	return _y;
}

void PointZZ_p2::setX(const ZZ_p2& x_){
	_x = x_;
}
void PointZZ_p2::setY(const ZZ_p2& y_){
	_y = y_;
}