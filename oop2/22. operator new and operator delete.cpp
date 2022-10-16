/*
* 重载::operator new, ::operator delete
*     ::operator new[], ::operator delete[]
*     ::代表全局的
*/

// 它们不可以被声明于一个namespace内
// 小心，这个影响无远弗界，因为是global
inline void* operator new(size_t size) //size 是由编译器传进来的
{ cout << "jjhou global new() \n";    return myAlloc(size); }

inline void* operator new[](size_t size)
{ cout << "jjhou global new[]() \n";    return myAlloc(size); }

inline void operator delete(void* ptr) 
{ cout << "jjhou global delete() \n";    myFree(ptr); }

inline void operator delete[](void* ptr) 
{ cout << "jjhou global delete[]() \n";    myFree(ptr); }

void* myAlloc(size_t size)
{ return malloc(size); }

void myFree(void* ptr)
{ return free(ptr); }

/*
* 重载 member operator new/delete
* 接管了new/delete通常可以做内存池
*/
class Foo{
public:
    void* operator new(size_t);
    void operator delete(void* , size_t); // size_t is optional
};
// use example
Foo* p = new Foo;
    // 分解为=====================>
    try{
        void* mem = operator new(sizeof(Foo));
        p = static_cast<Foo*>(mem);
        p->Foo:Foo();
    }
delete p;
    // 分解为=====================>
    p->~Foo();
    operator delete(p);

/*
* 重载 member operator new[]/delete[]
* 接管了new[]/delete[]通常可以做内存池
*/
class Foo{
public:
    void* operator new[](size_t);
    void operator delete[](void* , size_t); // size_t is optional
};
// use example
Foo* p = new Foo[N];
    // 分解为=====================>
    try{
        void* mem = operator new(sizeof(Foo)*N + 4);
        p = static_cast<Foo*>(mem);
        p->Foo:Foo(); //N次
    }
delete p;
    // 分解为=====================>
    p->~Foo(); //N次
    operator delete(p);