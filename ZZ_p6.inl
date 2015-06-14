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
    ZZ_p2 t[3], v[3], temp_prod[3];
    // prod._a_1 = ((a_._a_1) * (b_._a_1)) + ((ZZ_p2::cnr() * ZZ_p2::cnr() * ZZ_p2::cnr()) * ((a_._a_2)*(b_._a_3))*((a_._a_3)*(b_._a_2)));
    // prod._a_2 = ((a_._a_1) * (b_._a_2)) + ((a_._a_2) * (b_._a_1)) + ((ZZ_p6::cnrCubeP2()) * (a_._a_3) * (b_._a_3));
    // prod._a_3 = ((a_._a_2) * (b_._a_2)) + ((a_._a_1) * (b_._a_3)) + ((a_._a_3) * (b_._a_1));

    //1
    v[0] = a_.getFirst() * b_.getFirst();
    
    //2
    v[1] = a_.getSecond() * b_.getSecond();

    //3
    v[2] = a_.getThird() * b_.getThird();

    //4
    t[0].setFirst(a_.getSecond().getFirst() + a_.getThird().getFirst());
    t[0].setSecond(a_.getSecond().getSecond() + a_.getThird().getSecond());

    //5
    t[1].setFirst(b_.getSecond().getFirst() + b_.getThird().getFirst());
    t[1].setSecond(b_.getSecond().getSecond() + b_.getThird().getSecond());

    //6
    t[2] = t[0] * t[1];

    //7
    t[0].setFirst(v[0].getFirst() + v[1].getFirst());
    t[0].setSecond(v[0].getSecond() - v[1].getSecond());

    //8
    t[2].setFirst(t[2].getFirst() - t[0].getFirst());
    t[2].setSecond(t[2].getSecond() - t[0].getSecond());

    //9
    t[2].setSecond(t[2].getSecond() + t[2].getSecond());

    //10
    temp_prod[0].setFirst(v[0].getFirst() - t[2].getSecond());
    temp_prod[0].setSecond(v[0].getSecond() + t[2].getFirst());

    //11
    t[0].setFirst(a_.getFirst().getFirst() + a_.getSecond().getFirst());
    t[0].setSecond(a_.getFirst().getSecond() + a_.getSecond().getSecond());

    //12
    t[1].setFirst(b_.getFirst().getFirst() + b_.getSecond().getFirst());
    t[1].setSecond(b_.getFirst().getSecond() + b_.getSecond().getSecond());

    //13
    t[2] = t[0] * t[1];

    //14
    t[0].setFirst(v[0].getFirst() + v[1].getFirst());
    t[0].setSecond(v[0].getSecond() - v[1].getSecond());

    //15
    t[1].setFirst(v[2].getSecond() + v[2].getSecond());

    //16
    t[0].setFirst(t[0].getFirst() + t[1].getFirst());
    t[0].setSecond(v[2].getFirst() - t[0].getSecond());

    //17
    temp_prod[1].setFirst(t[2].getFirst() - t[0].getFirst());
    temp_prod[1].setSecond(t[2].getSecond() + t[0].getSecond());

    //18
    t[0].setFirst(a_.getFirst().getFirst() + a_.getThird().getFirst());
    t[0].setSecond(a_.getFirst().getSecond() + a_.getThird().getSecond());

    //19
    t[1].setFirst(b_.getFirst().getFirst() + b_.getThird().getFirst());
    t[1].setSecond(b_.getFirst().getSecond() + b_.getThird().getSecond());

    //20
    t[2] = t[0] * t[1];

    //21
    t[0].setFirst(v[0].getFirst() + v[2].getFirst());
    t[0].setSecond(v[0].getSecond() + v[2].getSecond());

    //22
    t[0].setFirst(v[1].getFirst() - t[0].getFirst());
    t[0].setSecond(v[1].getSecond() - t[0].getSecond());

    //23
    temp_prod[2].setFirst(t[2].getFirst() + t[0].getFirst());
    temp_prod[2].setSecond(t[2].getSecond() + t[0].getSecond());

    ZZ_p6 prod(temp_prod[0], temp_prod[1], temp_prod[2]);
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

void init(const ZZ_p6& qnr_){
    ZZ_p6::_qnr = qnr_;
    ZZ_p6::_zero = ZZ_p2::zero();
    ZZ_p6::_unity = ZZ_p2::unity();
}
// ZZ_p2::init(p) sets the modulus to p (p > 1)

const ZZ_p6& qnr(){
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