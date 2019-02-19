//自定义键值： less模板定制

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
};


template <> //function-template-specialization
    struct less<Person>{
    public :
        bool operator()(const Person &p1, const Person &p2) const {
            return (p1.age < p2.age) || (p1.age == p2.age && p1.name.length() < p2.name.length());
        }
};

int main(int argc, char* argv[]){
	map<Person, int> group; //map<Person, int, MyCompare> group;
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