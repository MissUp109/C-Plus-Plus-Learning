#include <iostream>

using namespace std;

template<class T>
class A{
public:
	virtual void f1();
	virtual void f2() = 0;
};

template<class T> void A<T>::f1(){
	cout << "A::f1()" << endl;
}

template<class T>
class B : public A<T>{
public:
	void f1();
	void f2();
};

template<class T> void B<T>::f1(){
	cout << "B::f1()" << endl;
}

template<class T> void B<T>::f2(){
	cout << "B::f2()" << endl;
}

int main(){
	//A<int>* p1 = new A<int>; p1->f1();
	B<int>* p2 = new B<int>; p2->f1();
	A<int>* p3 = new B<int>; p3->f1();	
}