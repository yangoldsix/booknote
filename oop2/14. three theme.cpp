/*
* variadic templates(since C++11) 数量不定的模板参数
*/
void print() //必须要加上的，虽然什么都没有实现
{

}

template<typename T, typename... Types> //typename...是个‘关键词’, ...要保留，不是省略
void print(const T& firstArg, const Types& ...args)
{
    cout<<firstArg<<endl;
    print(args...); //当调用到最后一个 时，调用的是上面的print()，是空的，所以调用完之后会停止print。
}
// Inside variadic templates, use:
// sizeof...(args)
// yields the number of arguments.

// ...就是一个所谓的pack（包）
// 用于template parameters,就是template parameters pack（模板参数包）
// 用于function parameters types,function parameters types pack（函数参数类型包）
// 用于function parameters,就是function parameters pack（函数参数包）

/*
* auto (since C++11)
*/
list<string> c;
list<string>::iterator ite;
ite = find(c.begin(), c.end(), target);

// ==============================>
list<string> c;
auto ite = find(c.begin(), c.end(), target);

// useless example
auto ite;
ite = find(c.begin(), c.end(), target);

/*
* ranged-base for (since C++11)
*/
for (decl : coll){
    statement
}

for(int i : {2, 3, 5, 7, 9, 11, 13, 17, 19}){
    cout << i << endl;
}

vector<double> vec;
// pass by value
for(auto elem : vec) {
    cout << elem <<endl; //如果elem*3，vec里面的元素的值不会改变
}
// pass by reference
for(auto& elem : vec) {
    elem *= 3； // vec里面的元素的值会改变
}