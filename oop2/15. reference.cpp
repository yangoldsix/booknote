/* reference */
int x = 0;
// p is a pointer to x
int* p = &x;
// r is a reference to x
int& r = x;     // r 代表 x。现在r，x 都是0
int x2 = 5;

r = x2;     // r不能重新代表其他物体。现在r，x都是5
int& r2 = r;    // 现在 r2 是5（r2代表r：亦相当于代表x）

// 注意：
// 1. sizeof(r) == sizeof(x)
// 2. &x == &r;
// object和其reference的大小相同，地址也相同（全都是假象）

/* example */
typedef struct Stag { int a, b, c, d; } S;
int main(){
    double x=0;
    double* p = &x; //p指向x，p的值是x的地址
    double& r = x;  //r代表x，现在r，x都是0

    cout << sizeof(x) << endl;  //8
    cout << sizeof(p) << endl;  //4
    cout << sizeof(r) << endl;  //8 
    cout << p << endl;          //0065FDFC
    cout << *p << endl;         //0
    cout << x << endl;          //0
    cout << r << endl;          //0
    cout << &x << endl;         //0065FDFC
    cout << &r << endl;         //0065FDFC

    S s;
    S& rs = s;
    cout << sizeof(s) << endl;  //16
    cout << sizeof(rs) << endl; //16
    cout << &s << endl;         //0065FDE8
    cout << &rs << endl;        //0065FDE8
}

/* reference的常见用途 */
void func1(Cls* pobj)   { pobj->xxx(); }
void func2(Cls obj)     { obj.xxx(); }      // 被调用端写法相同，很好
void func3(Cls& obj)    { obj.xxx(); }      // 被调用端写法相同，很好
...
Cls obj;
func1(&obj);    //接口不同，困扰
func2(obj);     //调用端接口相同，很好
func3(obj);     //调用端接口相同，很好

//reference 通常不用于声明变量，而用于参数类型(parameters type)和返回类型(return type)的描述。

//以下被视为"same signature"(所以二者不能同时存在)：
double imag(const double& im) {...}
double imag(const double im) {...}
//signature是指：imag(const double im)部分，不含返回类型的部分。

// Q: const是不是函数签名的一部分？
// A: 是的，所以以下两种可以同时存在：
double imag(const double& im) const {...}
double imag(const double im) {...}

