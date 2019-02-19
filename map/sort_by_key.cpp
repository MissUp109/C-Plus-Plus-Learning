#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
	map<string, int, greater<string>> test;
	test["Alice"] = 3;
	test["Cindy"] = 11;
	test["Bob"] = 7;

	for(auto itr = test.begin(); itr != test.end(); ++itr){
		cout << itr->first << ": " << itr->second << endl;
	}
	return 0;
}

/**/
//Alice: 3
//Bob: 7
//Cindy: 11

/* greater<string> output*/
//Cindy: 11
//Bob: 7
//Alice: 3
