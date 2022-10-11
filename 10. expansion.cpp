/* 进一步补充：static */
class Accout{
public:
    static double m_rate; //声明
    static void set_rate(const double& x) {m_rate = x;}
};

int main(){
    // 调用static函数的方式有二：
    Accout::set_rate(5.0); //（1）通过object调用

    Accout a;
    a.set_rate(7.0); //（2）通过class object调用
}

/* 
* 进一步补充：把ctors放在private区 
* use example:
* A::getInstance().setup();
*/
// Singleton
class A{
public:
    static A& getInstance( return a; );
    setup() {...}
private:
    A();
    A(const A& rhs);
    static A a; //但如果没有其他地方调用getInstance，仍会创建这个，浪费资源
    ...
};

// Meyers Singleton
class A{
public:
    static A& getInstance();
    setup() {...}
private:
    A();
    A(const A& rhs);
    ...
};

A& A::getInstance()
{
    static A a;
    return a;
}

/* 进一步补充：cout */
class _IO_ostream_withassign:public ostream {
    ...
};

extern _IO_ostream_withassign cout;

/* 进一步补充：class template 类模板 */
template<typename T>
class complex
{
public:
    complex(T r = 0, T i = 0):re(r), im(i)
    { }
    complex& operator += (const complex&);
    T real () const {return re;};
    T imag () const {return im;};
private:
    T re, im;
}
// use example
{
    complex<double> c1(2.5, 1.5);
    complex<int> c2(2, 6);
}

/* 进一步补充：function template 函数模板 */
stone r1(2, 3), r2(3, 3), r3;
r3 = min(r1, r2);
// ===========>
// 编译器会对function template进行实参推导（argument deduction）
// ===========>
template <class T>
inline
const T& min(const T& a, const T& b)
{
    return b < a ? b : a;
}
// ===========>
// 实参推导的结果，T为stone，于是调用stone::operator<
// ===========>
class stone
{
public:
    stone(int w, int h, int we)
        : _w(w), _h(h), _weight(we)
    { }

    bool operator< (const stone& rhs) const
    { return _weight < rhs._weight; }
private:
    int _w, _h, _weight;     
};

/* 进一步补充：namespace */
namespace std
{ ... };

// use directive(命令)
#include <iostream.h>
using namespace std;
int main()
{
    cin << ...;
    cout << ...;
    return 0;
}

// use declaration(声明)
#include <iostream.h>
using std::cout;
int main()
{
    std::cin << ...;
    cout << ...;
    return 0;
}

#include <iostream.h>
int main()
{
    std::cin << ...;
    std::cout << ...;
    return 0;
}