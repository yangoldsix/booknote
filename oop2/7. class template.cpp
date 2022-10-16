/* 
* class template, 类模板 
*/
template<typename T>
class complex
{
public:
    complex (T r = 0, T i = 0)
        : re(r), im(i)
    { }
    complex& operator += (const complex&);
    T real() const { return re; }
    T imag() const { return im; }
private:
    T re, im;

    friend complex& __doapl(complex*, const complex&);
};

// ues example
{
    complex<double> c1(2.5, 1,5);
    complex<int> c2(2, 6);
}

