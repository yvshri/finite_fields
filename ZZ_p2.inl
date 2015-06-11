ZZ_p2::ZZ_p2(ZZ_p a_1_, ZZ_p a_2_):_a_1(a_1_), _a_2(a_2_){

}

ZZ_p2::ZZ_p2(const ZZ_p2& a){
    _a_1 = a._a_1;
    _a_1 = a._a_2;
}

ZZ_p2::ZZ_p2(const ZZ_p& a_){
    _a_1 = a_;
    _a_2 = 0;
}

ZZ_p2::~ZZ_p2(){

}

ZZ_p2& ZZ_p2::operator=(const ZZ_p2& a_){
    _a_1 = a_._a_1;
    _a_1 = a_._a_2;
    return *this;
}
ZZ_p2& ZZ_p2::operator=(const ZZ_p& a_1_){
    _a_1 = a_1_;
    _a_2 = 0;
    return *this;
}

// ZZ_p2& operator=(const mpz_t& a); // assignment
// ZZ_p2& operator=(long a); // assignment


ZZ_p2 operator+(const ZZ_p2& a_, const ZZ_p2& b_){
    ZZ_p2 sum;
    sum._a_1 = a_._a_1 + b_._a_1;
    sum._a_2 = a_._a_2 + b_._a_2;
    return sum;
}
ZZ_p2& operator+=(ZZ_p2& x_, const ZZ_p2& b_){
    x_._a_1 = x_._a_1 + b_._a_1;
    x_._a_2 = x_._a_2 + b_._a_2;
    return x_;
}
// friend void add(ZZ_p& x, const ZZ_p& a, const ZZ_p& b); // x = a + b


ZZ_p2 operator*(const ZZ_p2& a_, const ZZ_p2& b_){
    ZZ_p2 prod;
    prod._a_1 = (a_._a_1) * (b_._a_1) + ZZ_p2::qnrSquare() * (a_._a_2) * (b_._a_2);
    prod._a_2 = (a_._a_1) * (b_._a_2) + (a_._a_2) * (b_._a_1);
    return prod;
}

ZZ_p2& operator*=(ZZ_p2& x_, const ZZ_p2& b_){
    x_._a_1 = (x_._a_1) * (b_._a_1) + ZZ_p2::qnrSquare() * (x_._a_2) * (b_._a_2);
    x_._a_2 = (x_._a_1) * (b_._a_2) + (x_._a_2) * (b_._a_1);
    return x_;
}

ZZ_p2 operator*(const ZZ_p2& a_, const ZZ_p& b_){
    ZZ_p2 prod;
    prod._a_1 = (a_._a_1) * (b_);
    prod._a_2 = (a_._a_2) * (b_);
    return prod;
}

ZZ_p2& operator*=(ZZ_p2& x_, const ZZ_p& b_){
    x_._a_1 = (x_._a_1) * (b_);
    x_._a_2 = (x_._a_2) * (b_);
    return x_;
}

// friend ZZ_p& operator*=(ZZ_p& x, long b);
// friend void mul(ZZ_p& x, const ZZ_p& a, const ZZ_p& b); // x = a * b

void init(const ZZ_p& qnr_square_){
    ZZ_p2::_qnr_square = qnr_square_;
    ZZ_p2::zero = ZZ_p(0);
    ZZ_p2::unity = ZZ_p(1);
}
// ZZ_p::init(p) sets the modulus to p (p > 1)

const ZZ_p& qnrSquare(){
    return ZZ_p2::_qnr_square;
}
// ZZ_p::modulus() yields read-only reference to the current
// modulus

ostream& operator<<(ostream& s_, const ZZ_p2& a_){
    s_ << "(" << a_._a_1 << "," << a_._a_2 << ")";
    return s_; 
}
// friend istream& operator>>(istream& s, ZZ_p2& x_){
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