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
    complex (double r = 0, double i = 0) //default argument 默认实参
        : re(r), im (i) //initialization list 初始列
    { }
    complex& operator += {const complex&};
    double real () const { return re; } // 函数若在class body内定义完成，便自动成为inline候选人
    double imag () const { return im; } // 但最终是否inline由编译器决定
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

#endif