#ifndef __COMPLEX__     /* guard */
#define __COMPLEX__     /* 防卫式声明 */

#include <cmath>

/*
* forward declarations
* 前置声明
*/
class ostream;
class complex;

complex&
    __doapl(complex* ths, const complex& r);

/*
* class declarations
* 类-声明
* use example
* {
*    complex c1(2, 1);
*    complex c2;
*    ...
*  }
*/
class complex
{
public:
    complex (double r = 0, double i = 0) //default argument 默认实参(pass by value)
        : re(r), im (i) //initialization list 初始列
    { }

    /*
    * pass by reference(to const)
    * 尽可能地用pass by reference，因为value是整包拷到栈，reference只是4个字节，速度快。
    * 因为引用，改了数据会影响到其他数据。不允许更改数据，可以加const。
    */
    complex& operator += {const complex&};  //return by reference

    //return by value
    double real () const { return re; } // 函数若在class body内定义完成，便自动成为inline候选人,但最终是否inline由编译器决定
    double imag () const { return im; } // 实部虚部是不需改变的内容，所以加上const。const member function(常量成员函数)
private:
    double re, im;

    friend complex& __doapl(complex*, const complex&);
};

/*
* constructor
* ctor:构造函数
* ctor可以有很多个--overloading(重载) 
*/
{
    complex c1(2, 1);
    complex c2;
    complex* p = new complex(4);
}

/*
* access level
* 访问级别--err
* 访问级别--ok
*/
{
    complex c1(2, 1);
    //err
    cout << c1.re;
    cout << c1.im;
    //ok
    cout << c1.real();
    cout << c1.imag();
}

/*
* class template
* 模板
* use example
* {
*    complex<double> c1(2.5, 1.5);
*    complex<int> c2(2, 6);
*    ...
*  }
*/
template<typename T>
class complex
{
public:
    complex (T r = 0, T i = 0) : re(r), im (i)
    { }
    complex& operator += {const complex&};
    T real() const { return re; }
    T imag() const { return im; }
private:
    T re, im;

    friend complex& __doapl(complex*, const complex&);
};

/*
* class definition
* 类-定义
*/
complex::function ...

//什么情况下可以pass by reference：
//      除了不可以的情况，其他都可以
//什么情况下不可以pass by reference：
//      函数内定义的变量（local），函数运行结束后，local已经die了。

//自由取得friend的private成员
inline complex&
__doapl (complex* ths, const complex& r)
{
    ths->re += r.re;    //第一参数将会被改动
    ths->im += r.im;    //第二参数不会被改动
    return *ths; //return by reference:传递者无需知道接收者是以reference形式接收
}

/*
* operator overloading-1, 成员函数
* 操作符重载
* use example
* {
*   complex c1(2, 1);
*   complex c2(5);
*
*   c2 += c1;
* }
*/
//使用者：c2 += c1,可以用void代替complex&；但使用者：c3 += c2 += c1, 就不能void。
inline complex& 
complex::operator += (const complex& r) 
//complex::operator += (this, const complex& r)
//任何成员函数都有一个隐藏的“this”point，指向调用者。
{
    return __doapl(this, r);
}

/*
* operator overloading-2, 非成员函数（无this）
* use example
* {
*   complex c1(2, 1);
*   complex c2;
*
*   c2 = c1 + c2;
*   c2 = c1 + 5;
*   c2 = 7 + c1;
* }
*/
// 下面这些函数绝不可return by reference，因为，它们返回的必定是个local object。
inline complex
operator + (const complex& x, const complex& y)
{
    return complex(real(x)+real(y), imag(x)+imag(y));
}

inline complex
operator + (const complex& x, double y)
{
    return complex(real(x)+y, imag(x));
}

inline complex
operator + (double x, const complex& y)
{
    return complex(x+real(y), imag(y));
}

inline complex //这里是可以用 return by reference
operator + (const complex& x)
{
    return x;
}

inline complex //这个函数绝不可return by reference，因为其返回的必定是个local object。
operator - (const complex& x)
{
    return complex(-real(x), -imag(x));
}

/*
* use example
* {
*   complex c1(2, 1);
*   cout << conj(c1);
*   cout << c1 << conj(c1);
* }
*/
inline complex
conj (const complex& x)
{
    return complex(real(x), -imag(x));
}

ostream&
operator << (ostream& os, const complex& x)
{
    return os << '(' << real(x) << ',' << imag(x) << ')';
}

/* 
* 相同class的各个objects互为friends(友元)
* use example
* {
*   complex c1(2, 1);
*   complex c2;
*   c2.func(c1);
* }
*/
class complex
{
public:
    complex(double r = 0, double i = 0)
        : re(r), im(i)
    { }

    int func(const complex& param)
    { return param.re + param.im; }

private:
    double re, im;
}

/*********************************************************/
/*
* ctors放在private区
* use example
* A::getInstance().setup();
*/
class A{
public:
    static A& getInstance();  //Singleton
    setup() { ... }
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
#endif