//
// This program uses a simple user-defined function
// to provide a hash function for use in unordered_map.
// The function is passed in as a lambda expression to
// the unordered_map constructor.
// 
// Compile this example with Visual Studio 2010
// or g++ 4.5 using -std=c++0x
//
#include <iostream>
#include <unordered_map>
#include <string>
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

    bool operator==(const Person & p) const 
    {
        return name == p.name && age == p.age;
    }
};

int main(int argc, char* argv[])
{
    unordered_map<Person,int,std::function<size_t (const Person & p)>>
    ids(100, []( const Person & p )
             {
                 return hash<string>()(p.name) ^ hash<int>()(p.age);
             } );
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