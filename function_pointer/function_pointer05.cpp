//
//typedef定义函数指针
//

#include <iostream>
using namespace std;

float add(float a, float b)
{
    cout << "add: " << a + b << endl;
    return a + b;
}

float minu(float a, float b)
{
    cout << "minu: " << a - b << endl;
    return a - b;
}

//用pfunType 来表示float(*)(float, float)
typedef float(*pfunType)(float, float);

int main()
{
    pfunType p = &add;//定义函数指针变量
    p(3.33, 2.22);
    pfunType parry[2] = {&add, &minu};//定义函数指针数组
    parry[1](3.33, 2.22);
    //函数指针作为参数可以定义为：void fun(pfunType p)
    //函数指针作为返回值可以定义为：pfunType fun();

    return 0;
}