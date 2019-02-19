#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

typedef pair<string, int> Pair;

bool my_compare(const Pair &p1, const Pair &p2){
	return p1.second < p2.second;
}

struct MyCompare{
public:
	bool operator()(const Pair &p1, const Pair &p2) const{
		return p1.second < p2.second;
	}
};

int main(){
	map<string, int> test;
	test["Alice"] = 3;
	test["Cindy"] = 5;
	test["Bob"] = 7;

	cout << "> sort by key" << endl;
	for(auto itr = test.begin(); itr != test.end(); ++itr){
		cout << itr->first << ": " << itr->second << endl;
	}
	cout << endl;

	vector<Pair> vec;

	for(auto itr = test.begin(); itr != test.end(); ++itr){
		vec.push_back(make_pair(itr->first, itr->second));
	}

	sort(vec.begin(), vec.end(), MyCompare()); //my_compare或者MyCompare()都可以

	cout << "> sort by value" << endl;
	for(auto itr = vec.begin(); itr != vec.end(); ++itr){
		cout << itr->first << ": " << itr->second << endl;
	}

	return 0;
}

/*

     -output-

> sort by key
Alice: 3
Bob: 7
Cindy: 11

> sort by value
Alice: 3
Bob: 7
Cindy: 11

*/
