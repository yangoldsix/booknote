#include "string.h"

int main()
{
    String s1();
    String s2("hello");

    String s3(s1);  //拷贝构造
    cout << s3 << endl;
    s3 = s2;    //拷贝复制

    cout << s3 << endl;
}