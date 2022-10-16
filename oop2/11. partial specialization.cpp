/*
* partial specialization 模版偏特化 
*/

// 个数的偏
template<typename T, typename Alloc=...>
class vector
{
...
};
// 绑定=====>
template<typename Alloc=...>
class vector<bool, Alloc> //如果有多个参数，必须特化要连续，不能跳参数来特化。
{
...
};

// 范围的偏
template<typename T>
class C
{
    ...
};
// =======>
template<typename T>
class C<T*>
{
    ...
};
// 这样写也可以=======>
template<typename U>
class C<U*>
{
    ...
};
// use example
C<string> obj1;
C<string*> obj2;