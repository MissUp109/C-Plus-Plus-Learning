#include <iostream>
using namespace std;


class mCallback{
public:
	void mCallbackFunc(int time);
};

void mCallback::mCallbackFunc(int time){
	cout << "time: " << time << endl;
}

class Caller {
public:
	void callerFunc(void (mCallback::*fun)(int time), int time);
};

void Caller::callerFunc(void (mCallback::*fun)(int time), int time){
	if(time % 10 == 0){
		mCallback cb;
		cb.(*fun)(time);
	}
}

int main(){
	Caller caller;
	//mFun fun = &mCallback::mCallbackFunc;
	for(int i = 0; i < 100; ++i){
		caller.callerFunc(&mCallback::mCallbackFunc, i);
	}
}