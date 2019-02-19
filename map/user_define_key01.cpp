//自定义键值： 重载operator<()

#include <iostream>
#include <map>
#include <string>
using namespace std;

class Person{
public:
    string name;
    int age;

    Person(string n, int a){
        name = n;
        age = a;
    }

    bool operator<(const Person &p) const
    {
        return (age < p.age) || (age == p.age && name.length() < p.name.length()) ;
    }
};

int main(int argc, char* argv[]){
	map<Person, int> group;
	group[Person("Mark", 17)] = 40561;
    group[Person("Andrew",18)] = 40562;
    for ( auto ii = group.begin() ; ii != group.end() ; ii++ )
        cout << ii->first.name 
        << " "
        << ii->first.age
        << " : "
        << ii->second
        << endl;

    return 0;
}