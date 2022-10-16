/*
* function template, 函数模板
*/
stone r1(2, 3), r2(3, 3), r3;
r3 = min(r1, r2);
//编译器会对function template进行实参推导（argument deduction）
// =====================>
template <class T>
inline
const T& min(const T& a, const T& b)
{
    return b < a ? b : a;
}
//实参推导的结果，T为stone，于是调用stone::operator<
// =====================>
class stone
{
public:
    stone(int w, int h, int we)
        : _w(w), _h(h), _weight(we)
    { }

    bool operator< (const stone& rhs) const
    { return _weight < rhs._weight; }
private:
    int _w, _h, _weight;
};