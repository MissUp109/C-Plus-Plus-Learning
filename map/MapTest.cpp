//
//compare by key
//
#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef pair<char, int> PAIR;

struct person{
	string name;
	int age;
	person(string n, int a){
		this->name = n;
		this->age = a;
	}

	//自定义类型，需重载operator<
	bool operator< (const person& p) const {  
        return this->age < p.age;  
    } 
    //因为这里我们只比较了age，所以age相同会产生覆盖
};


struct CmpByKey{
	bool operator()(const char &c1, const char &c2) const{
		return c1 < c2;
	}
};

struct CmpByValue{
	bool operator()(const PAIR &r, const PAIR &l){
		return r.second < l.second;
	}
};

bool cmp_by_value(const PAIR &r, const PAIR &l){
	return r.second < l.second;
}


int main(int argc, char* argv[]){
	//map< char, int > test;
	//map< char, int, less<char> > test;
	//map< char, int, greater<char> > test;
	map<char, int, CmpByKey> test;
	for (int i = 97; i < 123; ++i){
		test.insert(make_pair((char)i, i));	
	}	

	for(map<char, int>::iterator iter = test.begin(); iter != test.end(); ++iter){
		cout << iter->first << " " << iter->second << endl;	
	}	
};


