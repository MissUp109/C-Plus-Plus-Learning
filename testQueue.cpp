#include <iostream>
#include <queue>
using namespace std;

void yangHuiTriangles(const int n){
	cout << 1 << endl;
	queue<int> myQueue;
	myQueue.push(1);
	
	for(int i = 2; i <= n; ++i){
		int s1 = 0, s2 = 0;
		for(int j = 1; j <= i - 1; ++j){
			s2 = myQueue.front();
			cout << s1 + s2 << " ";
			myQueue.pop();
			myQueue.push(s1 + s2);
			s1 = s2;
		}
		cout << "1" << endl;
		myQueue.push(1);
	}
}

int main(){
	yangHuiTriangles(5);
}