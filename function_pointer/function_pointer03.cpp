//
//函数指针作为返回值
//
#include <iostream>
using namespace std;

class test1
{
public:
    int fun(int a, char c)
    {
        cout << "this is fun call:" << a << " " << c << endl;
        return a;
    }
};

class test2
{
    public:
    //成员函数：fun1(double d) 
    //返回值：int(test::*)(int, char)，是test1的成员函数指针
    int (test1::*fun1(double d))(int, char)
    {
        cout << d << endl;
        return &test1::fun;
    }
};

int main()
{
    test1 mytest1;
    test2 mytest2;
    int (test1::*p)(int, char) = mytest2.fun1(3.33);
    (mytest1.*p)(1, 'a');
    return 0;
}