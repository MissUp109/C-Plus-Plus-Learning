//
// This program uses a function object to define
// a hash function for use in unordered_map.
// 
// Compile this example with Visual Studio 2010
// or g++ 4.5 using -std=c++0x
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <functional>
using namespace std;

class Person{
public:
    string name;
    int age;

    Person(string n, int a){
        name = n;
        age = a;
    }
};

namespace std{
    template<>
    struct equal_to<Person>{
    public:
        bool operator()(const Person &p1, const Person &p2) const
        {
            return p1.name == p2.name && p1.age == p2.age;
        }
        
    };

    template<>
    struct hash<Person>{
    public:
        size_t operator()(const Person &p) const 
        {
            return hash<string>()(p.name) ^ hash<int>()(p.age);
        }
        
    };

}


int main(int argc, char* argv[]){
	unordered_map<Person, int> ids;
	ids[Person("Mark", 17)] = 40561;
    ids[Person("Andrew",16)] = 40562;
    for ( auto ii = ids.begin() ; ii != ids.end() ; ii++ )
        cout << ii->first.name 
        << " "
        << ii->first.age
        << " : "
        << ii->second
        << endl;
    return 0;
}