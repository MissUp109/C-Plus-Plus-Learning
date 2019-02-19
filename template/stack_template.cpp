#include <iostream>
using namespace std;

template<class T>
class Stack{
private:
	T* stack;
	int capacity;
	int top;
public:
	Stack(int size = 100);
	~Stack();
	bool isEmpty();
	bool isFull();
	void push_back(const T &t);
	T pop_back();
	template<class T2>  operator Stack<T2>();
};

template<class T>
Stack<T>::Stack(int size){
	capacity = size;
	stack = new T[capacity];
	top = -1;
}

template<class T>
Stack<T>::~Stack(){
	top = -1;
	delete[] stack;
}

template<class T>
bool Stack<T>::isEmpty(){
	if(top >= 0) return false;
	else return true;
}

template<class T>
bool Stack<T>::isFull(){
	if(top < capacity - 1)
		return false;
	else return true;
}

template<class T>
void Stack<T>::push_back(const T &t){
	if(isFull()){
		cout << "is full" << endl;
		return;
	}
	stack[++top] = t;
}

template<class T>
T Stack<T>::pop_back(){
	if(isEmpty()){
		cout << "is empty" << endl;
		return 0;
	}
	top = top - 1;
	return stack[top + 1];
}

template <class T> 
template <class T2>  Stack<T>::operator Stack<T2>() {
    Stack<T2> StackT2;
    for (int i = 0; i <= top; i++) {
        StackT2.push_back((T2)stack[i]);
    }
    return StackT2;
}


class Shape{};

class Circle : public Shape{};

int main(){
	Stack<Circle *> cStack;
    Stack<Shape *> sStack;
    cStack.push_back(new Circle);
    sStack = cStack;	
}
