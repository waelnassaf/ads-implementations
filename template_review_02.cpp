// A contrubtion by Wael Assaf.
#include <iostream>
#include <string>
using namespace std;

template<class T1, class T2>

T1 sum (T1 x, T2 y) {
    return x + y;
}


int main()
{
    double x = 10.2, y = 20.3;
    int z    = 5, f = 8;
    
    cout << sum(z, x) << endl;
    
    return 0;
}
