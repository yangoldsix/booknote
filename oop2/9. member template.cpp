/*
* member template, 成员模板
*/
template <class T1, class T2>
struct pair{
    typedef T1 first_type;
    typedef T2 second_type;

    T1 first;
    T2 second;

    pair()
        : first(T1()), second(T2()) {}
    pair(const T1& a, const T2& b)
        : first(a), second(b) {}

    template <class U1, class U2> //成员模板
    pair(const pair<U1, U2>& p)
        : first(p.first), second(p.second) {}
};

// use example
class Base1 {};
class Derived1 : public Base1 { };

class Base2 {};
class Derived2 : public Base2 { };

// T1, T2
pair<Derived1, Derived2> p;
pair<Base1, Base2> p2(p);

// T1, T2                  // U1, U2
pair<Base1, Base2> p2(pair<Derived1, Derived2>);

/*********************标准库*********************/
template<typename _Tp>
class shared_ptr : public __shared_ptr<_Tp>
{
    template<typename _Tp>
    explicit shared_ptr(_Tp1* __p)
        : __shared_ptr<_Tp>(__p){ }
};

// 鱼             // 鲫鱼 
Base1* ptr = new Derived1;  // up-cast 指向鱼的指针，指向鲫鱼是没问题的，鲫鱼 is-a 鱼
shared_ptr<Base1> sptr(new Derived1); // 模拟 up-cast