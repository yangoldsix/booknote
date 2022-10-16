/*
* 对象模型(Object Model) : 关于 Dynamic Binding
*/
// C is-a B, B is-a A
B b;
A a = (A) b;
a.vfunc1(); // static binding

A* pa = new B;
pa->vfunc1(); // dynamic binding

pa = &b; // up cast too!
pa->vfunc1();   // dynamic binding. B::vfunc1()

// dynamic binding 的三个条件：
// 1. 通过指针：pa
// 2. 通过虚函数：vfunc1()
// 3. up cast: A* pa = new B