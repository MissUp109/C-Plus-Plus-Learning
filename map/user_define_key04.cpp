//自定义键值： std::function

#include <iostream>
#include <map>
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
};

bool MyCompare(const Person &p1, const Person &p2) {
    return (p1.age < p2.age) || (p1.age == p2.age && p1.name.length() < p2.name.length());
}

int main(int argc, char* argv[]){
	map<Person, int, function<bool(const Person &, const Person &)>> group(MyCompare);
    //上面声明可以替换成：map<Person, int, decltype(&MyCompare)> group(MyCompare);
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