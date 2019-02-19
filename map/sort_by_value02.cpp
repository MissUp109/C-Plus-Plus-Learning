//https://blog.csdn.net/qq_17550379/article/details/80959968

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

typedef pair<string, int> Pair;

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

	map<int, string> result;
	transform(test.begin(), test.end(), inserter(result, result.begin()), [](pair<string, int> a) { return pair<int, string>(a.second, a.first); });
	
	cout << "> sort by value" << endl;
	for(auto itr = result.begin(); itr != result.end(); ++itr){
		cout << itr->first << ": " << itr->second << endl;
	}

	return 0;
}
