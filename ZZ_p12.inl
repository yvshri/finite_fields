ZZ_p12::ZZ_p12(ZZ_p6 a_1_, ZZ_p6 a_2_):_a_1(a_1_), _a_2(a_2_){

}

ZZ_p12::ZZ_p12(const ZZ_p12& a){
    _a_1 = a._a_1;
    _a_2 = a._a_2;
}

ZZ_p12::ZZ_p12(const ZZ_p6& a_){
    _a_1 = a_;
    _a_2 = ZZ_p6::zero();
}

ZZ_p12::~ZZ_p12(){

}

ZZ_p12& ZZ_p12::operator=(const ZZ_p12& a_){
    _a_1 = a_._a_1;
    _a_2 = a_._a_2;
    return *this;
}
ZZ_p12& ZZ_p12::operator=(const ZZ_p6& a_1_){
    _a_1 = a_1_;
    _a_2 = ZZ_p6::zero();
    return *this;
}

// ZZ_p12& operator=(const mpz_t& a); // assignment
// ZZ_p12& operator=(long a); // assignment


ZZ_p12 operator+(const ZZ_p12& a_, const ZZ_p12& b_){
    ZZ_p12 sum;
    sum._a_1 = a_._a_1 + b_._a_1;
    sum._a_2 = a_._a_2 + b_._a_2;
    return sum;
}
ZZ_p12& operator+=(ZZ_p12& x_, const ZZ_p12& b_){
    // x_._a_1 = x_._a_1 + b_._a_1;
    // x_._a_2 = x_._a_2 + b_._a_2;
    x_ = x_ + b_;
    return x_;
}
// friend void add(ZZ_p6& x, const ZZ_p6& a, const ZZ_p6& b); // x = a + b


ZZ_p12 operator*(const ZZ_p12& a_, const ZZ_p12& b_){
    ZZ_p12 prod;
    prod._a_1 = (a_._a_1) * (b_._a_1) + ZZ_p6::qnr() * ZZ_p6::qnr() * (a_._a_2) * (b_._a_2);
    prod._a_2 = (a_._a_1) * (b_._a_2) + (a_._a_2) * (b_._a_1);
    return prod;
}

ZZ_p12& operator*=(ZZ_p12& x_, const ZZ_p12& b_){
    // x_._a_1 = (x_._a_1) * (b_._a_1) + ZZ_p12::qnrSquareP6() * (x_._a_2) * (b_._a_2);
    // x_._a_2 = (x_._a_1) * (b_._a_2) + (x_._a_2) * (b_._a_1);
    x_ = x_ * b_;
    return x_;
}

ZZ_p12 operator*(const ZZ_p12& a_, const ZZ_p6& b_){
    ZZ_p12 prod;
    prod._a_1 = (a_._a_1) * (b_);
    prod._a_2 = (a_._a_2) * (b_);
    return prod;
}

ZZ_p12& operator*=(ZZ_p12& x_, const ZZ_p6& b_){
    // x_._a_1 = (x_._a_1) * (b_);
    // x_._a_2 = (x_._a_2) * (b_);
    x_ = x_ * b_;
    return x_;
}

// friend ZZ_p6& operator*=(ZZ_p6& x, long b);
// friend void mul(ZZ_p6& x, const ZZ_p6& a, const ZZ_p6& b); // x = a * b

void init(){
    ZZ_p12::_zero = ZZ_p6::zero();
    ZZ_p12::_unity = ZZ_p6::unity();
}
// ZZ_p6::init(p) sets the modulus to p (p > 1)


// ZZ_p6::modulus() yields read-only reference to the current
// modulus
const ZZ_p12& ZZ_p12::zero(){
    return ZZ_p12::_zero;
}

const ZZ_p12& ZZ_p12::unity(){
    return ZZ_p12::_unity;
}

ZZ_p6 ZZ_p12::getFirst() const{
    return _a_1;
}

ZZ_p6 ZZ_p12::getSecond() const{
    return _a_2;
}

void ZZ_p12::setFirst(const ZZ_p6& a_1_){
    _a_1 = a_1_;
}
void ZZ_p12::setSecond(const ZZ_p6& a_2_){
    _a_2 = a_2_;
}

void setToUnity(ZZ_p12& x_){
    x_ = ZZ_p12::_unity;
}

void setToZero(ZZ_p12& x_){
    x_ = ZZ_p12::_zero;
}

ostream& operator<<(ostream& s_, const ZZ_p12& a_){
    s_ << "(" << a_._a_1 << "," << a_._a_2 << ")";
    return s_; 
}
// friend istream& operator>>(istream& s, ZZ_p12& x_){
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