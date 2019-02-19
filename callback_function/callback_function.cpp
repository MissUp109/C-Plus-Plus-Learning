#include <iostream>
 
typedef void (*Fun)(int);
 
void caller(Fun pCallback, int num)//宿主函数
{
	Fun p = pCallback;
 
	(*p)(num);
}
 
 
void callback(int num)//回调函数
{
	std::cout << "callback: " << num << std::endl;
}
 
int main(int argc, char* argv[])
{
	caller(callback, 2333);
	return 0;
}
