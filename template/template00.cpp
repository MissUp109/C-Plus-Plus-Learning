#include <iostream>

using namespace std;

/*
template<typename T>
bool templateTest(T t1, T t2){
	return t1 < t2;
}*/

class A{
public:
	template<typename T>
	bool templateTest(T t1, T t2);
};

template<typename T>
bool A::templateTest(T t1, T t2){
	return t1 < t2;
}

template<typename T>
class B{
public:
	bool templateTest(T t1, T t2);
};

template<typename T> 
bool B<T>::templateTest(T t1, T t2){
	return t1 < t2;
}

int main(){
	//A a;
	//cout << a.templateTest<int>(2, 1) << endl;
	B<int> b;
	cout << b.templateTest(2, 1) << endl;
}