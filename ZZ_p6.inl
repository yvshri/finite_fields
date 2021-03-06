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

ZZ_p6 operator-(const ZZ_p6& a_, const ZZ_p6& b_){
    ZZ_p6 sum;
    sum._a_1 = a_._a_1 - b_._a_1;
    sum._a_2 = a_._a_2 - b_._a_2;
    sum._a_3 = a_._a_3 - b_._a_3;
    return sum;
}
ZZ_p6& operator-=(ZZ_p6& x_, const ZZ_p6& b_){
    x_ = x_ - b_;
    return x_;
}

//Karatsuba multiplication
ZZ_p6 operator*(const ZZ_p6& a_, const ZZ_p6& b_){
    ZZ_p6 f[2];
    f[0] = a_;
    f[1] = b_;
    ZZ_p2 t[4], v_bar[3], v[3];

    //1
    v_bar[0] = f[0].getFirst() * f[1].getFirst();
    
    //2
    v_bar[1] = f[0].getSecond() * f[1].getSecond();

    //3
    v_bar[2] = f[0].getThird() * f[1].getThird();

    //4
    t[1].setFirst(f[0].getSecond().getFirst() + f[0].getThird().getFirst());
    t[1].setSecond(f[0].getSecond().getSecond() + f[0].getThird().getSecond());

    //5
    t[2].setFirst(f[1].getSecond().getFirst() + f[1].getThird().getFirst());
    t[2].setSecond(f[1].getSecond().getSecond() + f[1].getThird().getSecond());

    //6
    t[3] = t[1] * t[2];

    //7
    t[1].setFirst(v_bar[1].getFirst() + v_bar[2].getFirst());
    t[1].setSecond(v_bar[1].getSecond() - v_bar[2].getSecond());

    //8
    t[3].setFirst(t[3].getFirst() - t[1].getFirst());
    t[3].setSecond(t[3].getSecond() - t[1].getSecond());

    //9
    t[3].setSecond(t[3].getSecond() + t[3].getSecond());

    //10
    v[0].setFirst(v_bar[0].getFirst() - t[3].getSecond());
    v[0].setSecond(v_bar[0].getSecond() + t[3].getFirst());

    //11
    t[1].setFirst(f[0].getFirst().getFirst() + f[0].getSecond().getFirst());
    t[1].setSecond(f[0].getFirst().getSecond() + f[0].getSecond().getSecond());

    //12
    t[2].setFirst(f[1].getFirst().getFirst() + f[1].getSecond().getFirst());
    t[2].setSecond(f[1].getFirst().getSecond() + f[1].getSecond().getSecond());

    //13
    t[3] = t[1] * t[2];

    //14
    t[1].setFirst(v_bar[0].getFirst() + v_bar[1].getFirst());
    t[1].setSecond(v_bar[0].getSecond() - v_bar[1].getSecond());

    //15
    t[2].setFirst(v_bar[2].getSecond() + v_bar[2].getSecond());

    //16
    t[1].setFirst(t[1].getFirst() + t[2].getFirst());
    t[1].setSecond(v_bar[2].getFirst() - t[1].getSecond());

    //17
    v[1].setFirst(t[3].getFirst() - t[1].getFirst());
    v[1].setSecond(t[3].getSecond() + t[1].getSecond());

    //18
    t[1].setFirst(f[0].getFirst().getFirst() + f[0].getThird().getFirst());
    t[1].setSecond(f[0].getFirst().getSecond() + f[0].getThird().getSecond());

    //19
    t[2].setFirst(f[1].getFirst().getFirst() + f[1].getThird().getFirst());
    t[2].setSecond(f[1].getFirst().getSecond() + f[1].getThird().getSecond());

    //20
    t[3] = t[1] * t[2];

    //21
    t[1].setFirst(v_bar[0].getFirst() + v_bar[2].getFirst());
    t[1].setSecond(v_bar[0].getSecond() + v_bar[2].getSecond());

    //22
    t[1].setFirst(v_bar[1].getFirst() - t[1].getFirst());
    t[1].setSecond(v_bar[1].getSecond() - t[1].getSecond());

    //23
    v[2].setFirst(t[3].getFirst() + t[1].getFirst());
    v[2].setSecond(t[3].getSecond() + t[1].getSecond());

    ZZ_p6 prod(v[0], v[1], v[2]);
    return prod;    
}

ZZ_p6& operator*=(ZZ_p6& x_, const ZZ_p6& b_){
    // x_._f[0]1 = (x_._a_1) * (b_._a_1) + ZZ_p6::cnrCubeP2() * (x_._a_2) * (b_._a_2);
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

void ZZ_p6::init(const ZZ_p6& qnr_){
    ZZ_p6::_qnr = qnr_;
    ZZ_p6::_zero = ZZ_p2::zero();
    ZZ_p6::_unity = ZZ_p2::unity();
}
// ZZ_p2::init(p) sets the modulus to p (p > 1)

const ZZ_p6& ZZ_p6::qnr(){
    return ZZ_p6::_qnr;
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

ZZ_p2 ZZ_p6::getThird() const{
    return _a_3;
}


void ZZ_p6::setFirst(const ZZ_p2& a_1_){
    _a_1 = a_1_;
}
void ZZ_p6::setSecond(const ZZ_p2& a_2_){
    _a_2 = a_2_;
}

void ZZ_p6::setThird(const ZZ_p2& a_3_){
    _a_3 = a_3_;
}

void setToUnity(ZZ_p6& x_){
    x_ = ZZ_p6::_unity;
}

void setToZero(ZZ_p6& x_){
    x_ = ZZ_p6::_zero;
}

ostream& operator<<(ostream& s_, const ZZ_p6& a_){
    s_ << "(" << a_._a_1 << "," << a_._a_2  << "," << a_._a_3 << ")";
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