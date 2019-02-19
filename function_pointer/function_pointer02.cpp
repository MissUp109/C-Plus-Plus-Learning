//
//函数指针作为参数
//
#include <iostream>
using namespace std;

void fun(int k, char c)
{
    cout << "this is fun2 call: " << k << ", " << c << endl;
}

void fun1(void (*pfun)(int, char), int a, char c)
{
    pfun(a, c);
}

int main()
{
    fun1(fun, 1, 'a');
    return 0;
}