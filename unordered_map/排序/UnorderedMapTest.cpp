#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

struct person{
	string name;
	int age;
	person(string n, int a){
		this->name = n;
		this->age = a;
	}

	bool operator== (const person& p) const {  
        return name == p.name && age == p.age;  
    } 
};

namespace std{
	template<>
	struct  hash<person> : public _Bitwise_hash<person>
	{
		
	};

	inline bool operator ==(const person &p)

	struct hash<person>{

};

}

size_t hash_value(const person& p)  {  
	size_t res = 17;
	res = res * 31 + hash<string>()( p.name );
	res = res * 31 + hash<int>()( p.age );
	return res;
    //size_t seed = 0;  
    //hash_combine(seed, hash_value(p.name));  
    //hash_combine(seed, hash_value(p.age));  
    //return seed; 
}



int main(){
	typedef unordered_map<person, int> umap;
	umap map;
	/*
	for(int i = 0; i < 100; ++i){
		map.insert(make_pair((char)i, i));
	}*/
	person p1("tommy", 5);
	person p2("alice", 2);
	person p3("t4", 7);

	map.insert(umap::value_type(p1, 1));
	map.insert(umap::value_type(p2, 2));
	map.insert(umap::value_type(p3, 3));
	//map.insert(make_pair(p4, 1));

	for(unordered_map<person, int>::iterator iter = map.begin(); iter != map.end(); ++iter){
		cout << (iter->first).name << " " << iter->second << endl;
	}
	return 0;
}