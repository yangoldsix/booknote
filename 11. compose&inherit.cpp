//类图见ppt

/* Composition(复合)，表示has-a */
// Adapter
template <class T>
class queue{
    ...
protected:
    deque<T> c; // 底层容器
public:
    // 以下完全利用c的操作函数完成
    bool empty() const { return c.empty(); }
    void pop() { c.pop_front(); }
};
//构造由内而外
//queue的构造函数首先调用c的default构造函数，然后才执行自己的。
//queue::queue(...) : deque() {...};
//析构由外而内
//queue的析构函数首先执行自己的，然后才调用c的析构函数。
//queue::~queue(...) { ... ~deque() };

/* Delegation(委托).Composition by reference */

// file String.hpp
class StringRep;
class String {
public:
    String();
    String(const char* s);
    String(const String& s);
    String &operator=(const String& s);
    ~String();
......
private:
    StringRep* rep; //pimpl( Handle/Body )
};

// file String.cpp
#include "String.hpp"
namespace {
class StringRep {
friend class String;
    StringRep(const char* s);
    ~StringRep();
    int count;
    char* rep;
};  
} 

String::String() { ... }
...

/* Inheritance(继承),表示is-a */
struct _List_node_base
{
    _List_node_base* _M_next;
    _List_node_base* _M_prev;
};

template<typename _Tp>
struct _List_node : public _List_node_base
{
    _Tp _M_data;
};
//构造由内而外
//Deived的构造函数首先调用base的default构造函数，然后才执行自己的。
//Deived::Deived(...) : Base() { ... };

//析构由外而内
//Deived的析构函数首先执行自己，然后才调用Base的析构函数。
//Deived::~Deived(...) {... ~Base() };

//base class的dtor必须是virtual，否则会出现undefined behavior。

/* Inheritance(继承) with virtual functions(虚函数) */
// 成员函数可以分为三种：
// non-virtual函数：你不希望derived class重新定义（override，覆写）它。
// virtual函数：你希望derived class重新定义（override，覆写）它，且你对它已有默认定义。
// pure virtual函数：你希望derived class一定要重新定义（override，覆写）它，你对它没有默认定义。
class Shape{
public:
    virtual void draw() const = 0; // pure virtual
    virtual void error(const std::string& msg); // impure virtual
    int objectID() const; // non-virtual
    ...
};

/* Template Method 设计模式之一 */
// Application framework
clsss CDocument{
public:
    void OnFileOpen()
    {
        Serialize();
    }

    virtual void Serialize() {};
}

// Application
class CMyDoc : public CDocument
{
public:
    virtual Serialize() {...}
};
int main()
{
    CMyDoc myDoc;
    myDoc.OnFileOpen(); //子类调用父类函数
}

/* Delegation(委托) + Inheritance(继承) */
// 观察者模式
class Subject
{
    int m_value;
    vector<Observer*> m_views;
public:
    void attach(Observer* obs)
    {
        m_views.push_back(obs);
    }
    void set_val(int value)
    {
        m_value = value;
        notify();
    }
    void notify()
    {
        for(int i = 0; i < m_views.size(); ++i)
            m_view[i]->update(this, m_value);
    }
};
// Observer
class Observer
{
public:
    virtual void update(Subject* sub, int value) = 0;
};

// Composite 组合模式
class Component
{
    int value;
public:
    Component(int val) { value = val; }
    virtual void add(Component*) {}
};

class Composite : public Component
{
    vector<Component*> c;
public:
    Composite(int val):Component(val) {}

    void add(Component* elem){
        c.push_back(elem);
    }
};

class Primitive : public Component
{
public:
    Primitive(int val) : Component(val) {}
}