#include <iostream>
#include <string>

using namespace std;

class FuncObject {
public:
    void operator() (const string s) const{
        cout << s << endl;
    }
};

int main(){
	FuncObject test;
	test("hello world");
}