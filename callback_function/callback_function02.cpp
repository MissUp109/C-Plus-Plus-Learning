#include <iostream>
using namespace std;

typedef void (*mFun)(int time);

void caller(mFun fun, int time){
	if(time % 10 == 0){
		(*fun)(time);
	}
}

void mCallback(int time){
	cout << "time: " << time << endl;
}

int main(){
	for(int i = 0; i < 100; ++i){
		caller(mCallback, i);
	}
}