//函数对象适配器
#include <iostream>
#include <vector>
using namespace std;

bool GreaterThanThree(int num){
	if(num <= 10)
		return true;
	else 
		return false;
};

int main(){
	int a[5] =  {1, 3, 15, 7, 9};
	vector<int> vec(a, a + 5);
	//int iCount = count_if(vec.begin(),vec.end(), GreaterThanThree);
	//函数适配器第一种：绑定器(bind1st, bind2nd)
	int iCount1 = count_if(vec.begin(), vec.end(), bind2nd(less_equal<int>(), 10)); 
	cout << iCount1 << endl;

	//函数适配器第二种：取反器(not1, not2)
	int iCount2 = count_if(vec.begin(), vec.end(), not1(bind2nd(less_equal<int>(),10)));
	cout << iCount2 << endl;
}