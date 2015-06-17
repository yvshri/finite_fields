
ZZ_p::ZZ_p(){
    mpz_init(_num);
}

ZZ_p::ZZ_p(const ZZ_p& a_){
    mpz_init(_num);
    mpz_t result_a;
    mpz_init(result_a);
    a_.getNum(result_a);
    setNum(result_a);
    mpz_clear(result_a);
}

ZZ_p::ZZ_p(mpz_t num_){
    mpz_init(_num);
    setNum(num_);
}

// ZZ_p::ZZ_p(const long num_){
//     mpz_t num;
//     mpz_inits(_num, num, NULL);
//     mpz_set_si(num, num_);
//     setNum(num);
//     mpz_clear(num);
// }

ZZ_p::~ZZ_p(){
    mpz_clear(_num);
}

ZZ_p& ZZ_p::operator=(const ZZ_p& a_){
    mpz_t result_a;
    mpz_init(result_a);
    a_.getNum(result_a);
    setNum(result_a);
    mpz_clear(result_a);
    return *this;
}

ZZ_p& ZZ_p::operator=(mpz_t num_){
    setNum(num_);
    return *this;
}

// ZZ_p& ZZ_p::operator=(const long num_){
//     mpz_t num;
//     mpz_init(num);
//     mpz_set_si(num, num_);
//     setNum(num);
//     mpz_clear(num);
//     return *this;
// }

void ZZ_p::initConstants(){
    mpz_t zero, unity;
    mpz_init_set_ui(ZZ_p::_unity._num, 1);
    mpz_init_set_ui(ZZ_p::_zero._num, 0);
}

void ZZ_p::init(mpz_t p_){
    if(mpz_cmp_ui(p_, 2) < 0){
        cout << "prime should be greater than 1" << endl;
        //throw exception
    }else{
        cout << "Base Prime = " << p_ << endl;
        mpz_init_set(ZZ_p::_mod, p_);
    }
    initConstants();
}

void ZZ_p::init(const long p_){
    if(p_ < 2){
        cout << "prime should be greater than 1" << endl;
        //throw exception
    }else{
        cout << "Base Prime = " << p_ << endl;
        mpz_init_set_ui(ZZ_p::_mod, p_);
    }
    initConstants();
}

void ZZ_p::getModulus(mpz_t mod_){
    mpz_set(mod_, _mod);
}

void ZZ_p::getZ(mpz_t z_){
    mpz_set(z_, z);
}

const ZZ_p& ZZ_p::qnr(){
    return ZZ_p::_qnr;
}

const ZZ_p& ZZ_p::zero(){
    return ZZ_p::_zero;
}

const ZZ_p& ZZ_p::unity(){
    return ZZ_p::_unity;
}

/**************************************************************************\

                        Comparison

\**************************************************************************/


long operator==(const ZZ_p& a_, const ZZ_p& b_){
    mpz_t result_a, result_b;
    mpz_inits(result_a, result_b, NULL);
    a_.getNum(result_a);
    b_.getNum(result_b);
    if(0 == mpz_cmp(result_a, result_b)){
        mpz_clears(result_a, result_b, NULL);
        return 1;
    }
    mpz_clears(result_a, result_b, NULL);
    return 0;
}

long operator!=(const ZZ_p& a_, const ZZ_p& b_){
    mpz_t result_a, result_b;
    mpz_inits(result_a, result_b, NULL);
    a_.getNum(result_a);
    b_.getNum(result_b);
    if(0 == mpz_cmp(result_a, result_b)){
        mpz_clears(result_a, result_b, NULL);
        return 0;
    }
    mpz_clears(result_a, result_b, NULL);
    return 1;
}

// PROMOTIONS: the comparison operators provide promotions
// from long to ZZ_p on (a, b)

long IsZero(const ZZ_p& a_){
    if(a_ == ZZ_p::zero()){
        return 1;
    }
    return 0;
}

long IsOne(const ZZ_p& a_){
    if(a_ == ZZ_p::unity()){
        return 1;
    }
    return 0;
}


/**************************************************************************\

                          Addition 

\**************************************************************************/

// operator notation:

ZZ_p operator+(const ZZ_p& a_, const ZZ_p& b_){
    ZZ_p sum;
    mpz_t sum_num, result_a, result_b;
    mpz_inits(result_a, result_b, sum_num, NULL);
    a_.getNum(result_a);
    b_.getNum(result_b);
    mpz_add(sum_num, result_a, result_b);
    sum.setNum(sum_num);
    mpz_clears(result_a, result_b, sum_num, NULL);
    return sum;
}

ZZ_p operator-(const ZZ_p& a_, const ZZ_p& b_){
    ZZ_p sum;
    mpz_t sum_num, result_a, result_b;
    mpz_inits(result_a, result_b, sum_num, NULL);
    a_.getNum(result_a);
    b_.getNum(result_b);
    mpz_sub(sum_num, result_a, result_b);
    sum.setNum(sum_num);
    mpz_clears(result_a, result_b, sum_num, NULL);
    return sum;
}
ZZ_p operator-(const ZZ_p& a_){
    ZZ_p negative;
    mpz_t neg_num;
    mpz_init(neg_num);
    mpz_t result_a;
    mpz_init(result_a);
    a_.getNum(result_a);
    mpz_neg(neg_num, result_a);
    negative.setNum(neg_num);
    mpz_clear(neg_num);
} 

ZZ_p& operator+=(ZZ_p& x_, const ZZ_p& b_){
    x_ = x_ + b_;
    return x_;
}

ZZ_p& operator-=(ZZ_p& x_, const ZZ_p& b_){
    x_ = x_ - b_;
    return x_;
}

ZZ_p operator++(ZZ_p& x_){
    x_ = x_ + ZZ_p::unity();
    return x_;
}
ZZ_p operator++(ZZ_p& x_, int){
    ZZ_p y(x_);
    x_ = x_ + ZZ_p::unity();
    return y;
}  // postfix

ZZ_p operator--(ZZ_p& x_){
    x_ = x_ - ZZ_p::unity();
    return x_;
}
ZZ_p operator--(ZZ_p& x_, int){
    ZZ_p y(x_);
    x_ = x_ - ZZ_p::unity();
    return y;
}

// procedural versions:


void add(ZZ_p& x_, const ZZ_p& a_, const ZZ_p& b_){
    x_ = a_ + b_;
}
void sub(ZZ_p& x_, const ZZ_p& a_, const ZZ_p& b_){
    x_ = a_ - b_;
}
void negate(ZZ_p& x_, const ZZ_p& a_){
    x_ = -a_;
}

// PROMOTIONS: binary +, - and procedures add, sub provide promotions
// from long to ZZ_p on (a, b)


/**************************************************************************\

                        Multiplication 

\**************************************************************************/

// operator notation:

ZZ_p operator*(const ZZ_p& a_, const ZZ_p& b_){
    ZZ_p sum;
    mpz_t sum_num, result_a, result_b;
    mpz_inits(result_a, result_b, sum_num, NULL);
    a_.getNum(result_a);
    b_.getNum(result_b);
    mpz_mul(sum_num, result_a, result_b);
    sum.setNum(sum_num);
    mpz_clears(result_a, result_b, sum_num, NULL);
    return sum;
}

ZZ_p& operator*=(ZZ_p& x_, const ZZ_p& b_){
    x_ = x_ * b_;
    return x_;
}
// ZZ_p& operator*=(ZZ_p& x, long b);

// procedural versions:


void mul(ZZ_p& x_, const ZZ_p& a_, const ZZ_p& b_){
    x_ = a_ * b_;
}

void sqr(ZZ_p& x_, const ZZ_p& a_){
    ZZ_p sum;
    mpz_t sum_num, result_a;
    mpz_inits(result_a, sum_num, NULL);
    a_.getNum(result_a);
    mpz_mul(sum_num, result_a, result_a);
    x_.setNum(sum_num);
    mpz_clears(result_a, sum_num, NULL);
}
ZZ_p sqr(const ZZ_p& a_){
    ZZ_p sum;
    mpz_t sum_num, result_a;
    mpz_inits(result_a, sum_num, NULL);
    a_.getNum(result_a);
    mpz_mul(sum_num, result_a, result_a);
    sum.setNum(sum_num);
    mpz_clears(result_a, sum_num, NULL);
    return sum;
}

// PROMOTIONS: operator * and procedure mul provide promotions 
// from long to ZZ_p on (a, b)



/**************************************************************************\

                    Division

\**************************************************************************/


// operator notation:

ZZ_p operator/(const ZZ_p& a_, const ZZ_p& b_){
    ZZ_p quo;
    quo = a_ * inv(b_);
    return quo;
}

ZZ_p& operator/=(ZZ_p& x_, const ZZ_p& b_){
    x_ = x_ * inv(b_);
}
// ZZ_p& operator/=(ZZ_p& x, long b){

// }


// procedural versions:


void div(ZZ_p& x_, const ZZ_p& a_, const ZZ_p& b_){
    x_ = a_ / b_;
}

void inv(ZZ_p& x_, const ZZ_p& a_){
    mpz_t g, s, t, result_a, mod;
    mpz_inits(g, s, t, result_a, mod, NULL);
    a_.getNum(result_a);
    ZZ_p::getModulus(mod);
    mpz_gcdext(g, s, t, result_a, mod);
    x_.setNum(t);
    mpz_clears(g, s, t, result_a, mod, NULL);
}

ZZ_p inv(const ZZ_p& a_){
    ZZ_p x_;
    mpz_t g, s, t, result_a, mod;
    mpz_inits(g, s, t, result_a, mod, NULL);
    a_.getNum(result_a);
    ZZ_p::getModulus(mod);
    cout << mod << endl;
    mpz_gcdext(g, s, t, result_a, mod);
    x_.setNum(s);
    cout << s << endl;
    mpz_clears(g, s, t, result_a, NULL);
    return x_;
}





/**************************************************************************\

                      Input/Output

\**************************************************************************/


ostream& operator<<(ostream& s_, const ZZ_p& a_){
    mpz_t result_a;
    mpz_init(result_a);
    a_.getNum(result_a);
    s_ << result_a;
    mpz_clear(result_a);
    return s_;
}

// istream& operator>>(istream& s_, ZZ_p& x_){
//     mpz_t num;
//     mpz_init(num);
//     s_ >> num;
//     x_.setNum(num);
//     mpz_clear(num);
//     return s_;
// }


/**************************************************************************\

                                Exponentiation

\**************************************************************************/


void power(ZZ_p& x_, const ZZ_p& a_, mpz_t exp_){
    mpz_t rop, mod, num;
    mpz_inits(rop, mod, num, NULL);
    ZZ_p::getModulus(mod);
    a_.getNum(num);
    cout << "num " << num << " mod " << mod << " exp " << exp_ << endl;
    mpz_powm_sec(rop, num, exp_, mod);
    x_.setNum(rop);
    mpz_clears(rop, mod, num, NULL);
}

ZZ_p power(const ZZ_p& a, mpz_t exp_){
    ZZ_p x;
    mpz_t rop, mod, num;
    mpz_inits(rop, mod, num, NULL);
    ZZ_p::getModulus(mod);
    a.getNum(num);
    mpz_powm_sec(rop, num, exp_, mod);
    x.setNum(rop);
    mpz_clears(rop, mod, num, NULL);
    return x;
}

/**************************************************************************\

                     Miscellany

\**************************************************************************/

void setToZero(ZZ_p& x_){
    x_ = ZZ_p::zero();
}
void setToUnity(ZZ_p& x_){
    x_ = ZZ_p::unity();
}

void swap(ZZ_p& a_, ZZ_p& b_){
    mpz_t result_a, result_b;
    mpz_inits(result_a, result_b, NULL);
    a_.getNum(result_a);
    b_.getNum(result_b);
    a_.setNum(result_a);
    b_.setNum(result_b);
    mpz_clears(result_a, result_b, NULL);
}
// swap x and y (done by "pointer swapping", if possible).

void ZZ_p::swap(ZZ_p& a_){
    mpz_t result_a, result_b;
    mpz_inits(result_a, result_b, NULL);
    a_.getNum(result_a);
    getNum(result_b);
    a_.setNum(result_b);
    setNum(result_a);
    mpz_clears(result_a, result_b, NULL);
}

void ZZ_p::getNum(mpz_t result) const{
    mpz_set(result, _num);
}
void ZZ_p::setNum(mpz_t t_){
    mpz_t rem, mod;
    mpz_inits(rem, mod, NULL);
    ZZ_p::getModulus(mod);
    if(mpz_cmp_ui(mod, 0) == 0){
        // cout << "Mod zero error";
    }else{
        mpz_mod(rem, t_, mod);
    }
    mpz_set(_num, rem);
    mpz_clears(rem, mod, NULL);
}