#ifndef __MYSTRING__
#define __MYSTRING__

class String
{
public: //类带指针，就一定不用编译器默认的拷贝构造or拷贝赋值
    String(const char* cstr = 0);
    String(const String& str); //拷贝构造
    String& operator=(const String& str); //拷贝赋值
    ~String(); //析构
    char* get_c_str() const { return m_data; }
private:
    char* m_data;
}

/* ctor和dtor（构造函数 和 析构函数）
use example
{
    String s1();
    String s2("hello");

    String* p = new String("hello");
    delete p;
}
*/
inline
String::String(const char* cstr = 0)
{
    if(cstr){
        m_data = new char[strlen(cstr)+1];
        strcpy(m_data, cstr);
    }
    else{ //未指定初值
        m_data = new char[1];
        *m_data = '\0';
    }
}

inline
String::~String()
{
    delete[] m_data; //array new一定要搭配array delete，否则只唤醒1次dtor，造成memory leak。
}

/* copy ctor(拷贝构造函数) 
* use example
{
    String s1("hello");
    String s2(s1);
    // String s2 = s1;
}
*/
inline
String::String(const String& str)
{
    m_data = new char[ strlen(str.m_data) + 1 ]; //直接取另一个object的private data（兄弟之间互为friend）
    strcpy(m_data, str.m_data);
}

/* copy assignment operator（拷贝赋值函数）
* use example
{
    String s1("hello");
    String s2(s1);
    s2 = s1;
}
*/
String& String::operator=(const String& str)
{
    if(this == &str) //检测自我赋值(self assignment)
        return *this;
    
    delete[] m_data;
    m_data = new char[ strlen(str.m_data) + 1 ];
    strcpy(m_data, str.m_data);
    return *this; 
}

/*
* use example
{
    String s1("hello ");
    cout << s1;
}
*/
ostream& operator<<(ostream& os, const String& str)
{
    os << str.get_c_str();
    return os;
}

/* 所谓stack（栈），所谓heap（堆）*/

// stack，是存在于某作用域（scope）的一块内存空间（memory space）。
// 例如当你调用函数，函数本身即会形成一个stack用来放置它所接收的参数，以及返回地址。
// 在函数本体（function body）内声明的任何变量，其所使用的内存块都取自上述stack。

// heap，或谓system heap，是指由操作系统提供的一块global内存空间，
// 程序可动态分配（dynamic allocated）从某中获得若干区块（blocks）。
{
    class Complex { ... };
    ...
    {
        Complex c1(1, 2); //c1所占用的空间来自stack
        // c1便是所谓stack object，其生命在作用域（scope）结束之际结束。
        // 这种作用域内的object，又称为auto object，因为它会被[自动]清理。

        Complex* p = new Complex(3); //Complex(3)是个临时对象，占用的空间乃是以new分配而得。

        static Complex c2(1, 2);
        // c2便是所谓static object，其生命在作用域（scope）结束之后仍然存在，直到整个程序结束。
    }
}

/* global objects */
class Complex {};
...
Complex c3(1, 2);
int main() { }
// c3便是所谓global object，其生命在整个程序结束之后才结束。
// 你也可以把它视为一种static object，其作用域是[整个程序]。

/* heap objects */
class Complex {...};
...
{
    Complex* p = new Complex; //new的工作：先分配memory，再调用ctor。
    ...
    delete p; //delete的工作：先调用dtor，再释放memory。
}
// p所指的便是heap object，其生命在它被deleted之际结束。
// 没有delete，会出现内存泄漏（memory leak），因为当作用域结束，p所指的heap object仍然存在，
// 但指针p的生命却结束了，作用域之外再也看不到p（也就没机会detele p）。
#endif
