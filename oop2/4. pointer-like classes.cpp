/* pointer-like classes, 关于智能指针 */
template<class T>
class shared_ptr
{
public:
    T& operator*() const
    { return *px; }

    T* operator->() const
    { return px; }

    shared_ptr(T* p) : px(p) { }
private:
    T* px;
    long* pn;
......
};

struct Foo
{
    void method(void) { ... }
};

shared_ptr<Foo> sp(new Foo);
Foo f(*sp);
sp->method(); // 即 px->method();

/* pointer-like classes, 关于迭代器 */
// 以list为例
//T&
reference operator*() const
{
    return (*node).data;
}
//T*
pointer operator->() const
{
    return &(operator* ());
}

list<Foo>::iterator ite;
*ite; // 获得一个 Foo object
ite->method();
    // 意思是调用Foo::method()
    // 相当于(*ite).method();
    // 相当于(&(*ite))->method();