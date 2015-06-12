ZZ_p6::ZZ_p6(ZZ_p2 a_1_, ZZ_p2 a_2_, ZZ_p2 a_3_):_a_1(a_1_), _a_2(a_2_), _a_3(a_3_){

}

ZZ_p6::ZZ_p6(const ZZ_p6& a_){
    _a_1 = a_._a_1;
    _a_2 = a_._a_2;
    _a_3 = a_._a_3;
}

ZZ_p6::ZZ_p6(const ZZ_p2& a_1_){
    _a_1 = a_1_;
    _a_2 = ZZ_p2::zero();
    _a_3 = ZZ_p2::zero();
}

ZZ_p6::~ZZ_p6(){

}

ZZ_p6& ZZ_p6::operator=(const ZZ_p6& a_){
    _a_1 = a_._a_1;
    _a_2 = a_._a_2;
    _a_3 = a_._a_3;
    return *this;
}

ZZ_p6& ZZ_p6::operator=(const ZZ_p2& a_1_){
    _a_1 = a_1_;
    _a_2 = ZZ_p2::zero();
    _a_3 = ZZ_p2::zero();
    return *this;
}

// ZZ_p2& operator=(const mpz_t& a); // assignment
// ZZ_p2& operator=(long a); // assignment


ZZ_p6 operator+(const ZZ_p6& a_, const ZZ_p6& b_){
    ZZ_p6 sum;
    sum._a_1 = a_._a_1 + b_._a_1;
    sum._a_2 = a_._a_2 + b_._a_2;
    sum._a_3 = a_._a_3 + b_._a_3;
    return sum;
}
ZZ_p6& operator+=(ZZ_p6& x_, const ZZ_p6& b_){
    // x_._a_1 = x_._a_1 + b_._a_1;
    // x_._a_2 = x_._a_2 + b_._a_2;
    // x_._a_3 = x_._a_3 + b_._a_3;
    x_ = x_ + b_;
    return x_;
}
// friend void add(ZZ_p2& x, const ZZ_p2& a, const ZZ_p2& b); // x = a + b


ZZ_p6 operator*(const ZZ_p6& a_, const ZZ_p6& b_){
    ZZ_p6 prod;
    prod._a_1 = ((a_._a_1) * (b_._a_1)) + ((ZZ_p6::cnrCubeP2()) * ((a_._a_2)*(b_._a_3))*((a_._a_3)*(b_._a_2)));
    prod._a_2 = ((a_._a_1) * (b_._a_2)) + ((a_._a_2) * (b_._a_1)) + ((ZZ_p6::cnrCubeP2()) * (a_._a_3) * (b_._a_3));
    prod._a_3 = ((a_._a_2) * (b_._a_2)) + ((a_._a_1) * (b_._a_3)) + ((a_._a_3) * (b_._a_1));
    return prod;
}

ZZ_p6& operator*=(ZZ_p6& x_, const ZZ_p6& b_){
    // x_._a_1 = (x_._a_1) * (b_._a_1) + ZZ_p6::cnrCubeP2() * (x_._a_2) * (b_._a_2);
    // x_._a_2 = (x_._a_1) * (b_._a_2) + (x_._a_2) * (b_._a_1);
    x_ = x_ * b_;
    return x_;
}

ZZ_p6 operator*(const ZZ_p6& a_, const ZZ_p2& b_){
    ZZ_p6 prod;
    prod._a_1 = (a_._a_1) * (b_);
    prod._a_2 = (a_._a_2) * (b_);
    prod._a_3 = (a_._a_3) * (b_);
    return prod;
}

ZZ_p6& operator*=(ZZ_p6& x_, const ZZ_p2& b_){
    // x_._a_1 = (x_._a_1) * (b_);
    // x_._a_2 = (x_._a_2) * (b_);
    x_ = x_ * b_;
    return x_;
}

// friend ZZ_p2& operator*=(ZZ_p2& x, long b);
// friend void mul(ZZ_p2& x, const ZZ_p2& a, const ZZ_p2& b); // x = a * b

void init(const ZZ_p2& cnr_cube_){
    ZZ_p6::_cnr_cube = cnr_cube_;
    ZZ_p6::_zero = ZZ_p2::zero();
    ZZ_p6::_unity = ZZ_p2::unity();
}
// ZZ_p2::init(p) sets the modulus to p (p > 1)

const ZZ_p2& cnrCubeP2(){
    return ZZ_p6::_cnr_cube;
}
// ZZ_p2::modulus() yields read-only reference to the current
// modulus
const ZZ_p6& ZZ_p6::zero(){
    return ZZ_p6::_zero;
}

const ZZ_p6& ZZ_p6::unity(){
    return ZZ_p6::_unity;
}

ZZ_p2 ZZ_p6::getFirst() const{
    return _a_1;
}

ZZ_p2 ZZ_p6::getSecond() const{
    return _a_2;
}

void ZZ_p6::setFirst(const ZZ_p2& a_1_){
    _a_1 = a_1_;
}
void ZZ_p6::setSecond(const ZZ_p2& a_2_){
    _a_2 = a_2_;
}

void setToUnity(ZZ_p6& x_){
    x_ = ZZ_p6::_unity;
}

void setToZero(ZZ_p6& x_){
    x_ = ZZ_p6::_zero;
}

ostream& operator<<(ostream& s_, const ZZ_p6& a_){
    s_ << "(" << a_._a_1 << "," << a_._a_2 << ")";
    return s_; 
}
// friend istream& operator>>(istream& s, ZZ_p6& x_){
//     mpz_t a_1, a_2;
//     char brkt_open, brkt_close, comma;
//     s >> brkt_open;
//     s >> a_1;
//     s >> comma;
//     s >> a_2;
//     s >> brkt_close;
//     x_._a_1 = a_1;
//     x_._a_2 = a_2;
//     return s;
// }