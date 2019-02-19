#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ofstream outFile;
	outFile.open("test");
	if(!(outFile.is_open())){
		return 0;
	}
	outFile << "hello world." << endl;
	outFile.close();

	ifstream inFile;
	inFile.open("test");
	if(!(inFile.is_open())){
		return 0;
	}
	char str[20]; 
	inFile >> str;
	while(inFile.good()){
		inFile >> str;
	}
	if(inFile.eof()){
		cout << "eof" << endl;
	}
	cout << str << endl;
	inFile.close();
	return 0;	
}