/* 谈谈const */

///                                     const object                        non-const object
///                                 (data members不得变动)                  (data members可变动)
/// const member functions                  Yes                                     Yes
/// (保证不更改data members)

/// non-const member functions              No                                      Yes
/// (不保证data members不变)

const String str("hello world");
str.print();
// 如果当初设计 string::print() 时未指明 const,
// 那么上行便是经由const object调用non-const member function, 会出错。此非吾人所愿。

//non-const member functions 可调用 const member functions，反之则不行，编译不通过。

// class template std::basic_string<...> 有如下两个member functions:
charT
operator[] (size_type pos) const
{....../* 不必考虑COW */}

reference
operator[] (size_type pos)
{....../*必须考虑COW*/}  //COW：Copy On Write
//当成员函数的const和non-const版本同时存在，const object只会（只能）调用const版本，non-const object只会（只能）调用non-const版本。