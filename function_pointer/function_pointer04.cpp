//
//函数指针数组
//

#include <iostream>
using namespace std;

float add(float a, float b){
	return a + b;
}

float minu(float a, float b){
	return a - b;
}

int main()
{
    //定义一个函数指针数组，大小为2
    //里面存放float (*)(float, float)类型的指针
    float (*pfunArry[2])(float, float) = {&add, &minu};
    double k = pfunArry[0](3.33,2.22);// 调用
    cout << "add: " << k << endl;
    k = pfunArry[1](3.33,2.22);
    cout << "minu: " << k << endl;
    return 0;
}