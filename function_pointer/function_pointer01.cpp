#include <iostream>
using namespace std;

class test {
public:
    test()
    {
        cout << "constructor" << endl;
    }

    int fun1(int a, char c)
    {
        cout << "this is fun1 call:" << a << " " << c << endl;
        return a;
    }

    void fun2(double d) const
    {
        cout << "this is fun2 call:" << d << endl;
    }

    static double fun3(char buf[])
    {
        cout << "this is fun3 call:" << buf << endl;
        return 3.14;
    }
};

int main()
{
    // 类的静态成员函数指针
    double (*pstatic)(char buf[]) = NULL;//不需要加类名
    pstatic = test::fun3; //可以不加取地址符号
    pstatic("myclaa");
    pstatic = &test::fun3;//加取地址符号
    (*pstatic)("xyz");

    //普通成员函数
    int (test::*pfun)(int, char) = NULL; //一定要加类名
    pfun = &test::fun1; //一定要加取地址符号
    test mytest;
    (mytest.*pfun)(1, 'a'); //调用时一定要加类的对象名和*符号

    //const 函数（基本普通成员函数相同）
    void (test::*pconst)(double)const = NULL; //一定要加const
    pconst = &test::fun2;
    test mytest2;
    (mytest2.*pconst)(3.33);

    return 0;
}