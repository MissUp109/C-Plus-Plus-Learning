//函数对象适配器2
#include <functional>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>
#define ASSERT assert
using namespace std;
class Rand : public binary_function<int, int, int> {
public:
    Rand(){ srand((unsigned int)time(NULL)); }
    
    int operator()(int minval, int maxval) const
    {
        //判断传参的好方法
        ASSERT(maxval>minval);
        ASSERT(minval>=0);
        ASSERT(maxval<=RAND_MAX);
        return (rand()%(maxval-minval)) + minval;
    }
};

int main()
{
    cout << Rand()(1, 5) << endl; //[1,5)
    cout << bind1st(Rand(), 20)(30) << endl;
    return 0;
}