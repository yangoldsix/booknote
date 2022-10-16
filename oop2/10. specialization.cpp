/*
* specialization, 模板特化
*/
// 模板泛化
template <class Key>
struct hash { };

// 模板特化
template<>
struct hash<char>
{
    size_t operator() (char x) const { return x; }
};

template<>
struct hash<int>
{
    size_t operator() (int x) const { return x; }
};

template<>
struct hash<long>
{
    size_t operator() (long x) const { return x; }
};

//use example
cout << hash<long>()(1000);

