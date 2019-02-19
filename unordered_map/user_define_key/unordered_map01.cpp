//
// Compile this example with Visual Studio 2010
// or g++ 4.5 using -std=c++0x
//
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

typedef string Name;

int main(int argc, char* argv[])
{
    unordered_map<Name,int> ids;
    ids["Mark Nelson"] = 40561;
    ids["Andrew Binstock"] = 40562;
    for ( auto ii = ids.begin() ; ii != ids.end() ; ii++ )
        cout << ii->first << " : " << ii->second << endl;
    return 0;
}