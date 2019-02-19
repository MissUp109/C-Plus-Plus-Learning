//函数对象大多按值传递

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FuncObject{
public: 
	FuncObject(int n = 0) : num(n), count(1){}

	bool operator()(int) {
		return count++ == num;
	}

	int GetCount(){
		return count;
	}
private:
	int count;
	int num;
};

int main(){
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> dest(a, a + 10);
	FuncObject test(3);  

	//证明一般为按值传递
	//vector<int>::iterator itr = find_if(dest.begin(),dest.end(), test);  	
	//cout << "3rd:" << *itr << endl;  //9rd:3
	//cout << "State:" << test.GetCount() << endl; //State:1


	//remove情况
	remove_if(dest.begin(), dest.end(), test); 
	for(vector<int>::size_type i = 0; i < 10; ++i) {  
		cout << dest[i] << endl; //cout:1 2 4 5 6 7 8 9 10 10 算法库绝对不改变容器大小，被删的元素只是被丢到最后
	} 

}
