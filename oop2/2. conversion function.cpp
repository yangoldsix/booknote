/* conversion function 转换函数
* use example
  Fraction f(3, 5);
  double d = 4 + f; // 调用operator double()将 f 转为 0.6
*/
class Fraction
{
public:
    Fraction(int num, int den = 1)
        :m_numerator(num), m_denominator(den) { }
    
    operator double() const {       //转换函数
        return (double)(m_numerator / m_denominator);
    }
private:
    int m_numerator;    //分子
    int m_denominator;  //分母
};

/* non-explicit-one-argument ctor
* use example
  Fraction f(3, 5);
  Fraction d2 = f + 4;  // 调用 non-explicit ctor 将4转为Fraction(4, 1)
                        // 然后调用operator+
*/
class Fraction
{
public:
    Fraction(int num, int den = 1)   // non-explicit-one-argument ctor
        :m_numerator(num), m_denominator(den) { }
    
    Fraction operator+(const Fraction& f){
        return Fraction(...);
    }
private:
    int m_numerator;    //分子
    int m_denominator;  //分母
};

/* conversion function vs. non-explicit-one-argument ctor
* useless example
  Fraction f(3, 5);
  Fraction d2=f+4; //[error]ambiguous
*/
class Fraction
{
public:
    Fraction(int num, int den = 1)   
        :m_numerator(num), m_denominator(den) { }

    operator double() const {    
        return (double)(m_numerator / m_denominator);
    }

    Fraction operator+(const Fraction& f){
        return Fraction(...);
    }
private:
    int m_numerator;    //分子
    int m_denominator;  //分母
};

/* explicit-one-argument ctor
* useless example
  Fraction f(3, 5);
  Fraction d2=f+4; //[error] conversion from 'double' to 'Fraction' request. 
*/
class Fraction
{
public:
    explicit Fraction(int num, int den = 1)    // 90% 的explicit都用在构造函数前
        :m_numerator(num), m_denominator(den) { }

    operator double() const {    
        return (double)(m_numerator / m_denominator);
    }

    Fraction operator+(const Fraction& f){
        return Fraction(...);
    }
private:
    int m_numerator;    //分子
    int m_denominator;  //分母
};