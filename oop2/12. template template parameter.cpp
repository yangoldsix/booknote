/*
* template template parameter, 模板模板参数
*/
template<typename T,
         template <typename T>  // 模板模板参数
            class Container     // 模板模板参数
        >
class XCls
{
private:
    Container<T> c;
public:
    ...
};
// useless example
XCls<string, list> mylst1;

// use example
template<typename T>
using Lst = list<T, allocator<T>>;

XCls<string, Lst> mylst2;

// ===============================
template<typename T,
         template <typename T>  // 模板模板参数
            class SmartPtr     // 模板模板参数
        >
class XCls
{
private:
    SmartPtr<T> sp;
public:
    XCls() : sp(new T) { }
};

// use example
XCls<string, shared_ptr> p1;
XCls<string, auto_ptr> p1;

/* 这个不是 template template parameter */
template <class T, class Sequence = deque<T>>
class stack{
    friend bool operator== <> (const stack&, const stack&);
    friend bool operator< <> (const stack&, const stack&);

protected:
    Sequence c; //底层容器
};

//use example
stack<int> s1;
stack<int, list<int>> s2;