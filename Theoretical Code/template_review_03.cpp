// A contrubtion by Wael Assaf.
#include <iostream>
#include <string>
using namespace std;

template<class T1, class T2>

T1 lower (T1 x, T2 y) {
    return x > y ? y : x; // Shorthand IF statement 
}


int main()
{
    int x = 19;
    double y = 12.122;
    
    cout << lower(x, y) << endl; // Output: 12. Which is not true
    cout << lower(y, x) << endl; // Output: 12.122 but not so valid method.
    cout << lower<double>(x, y) << endl; // Good method.
    cout << lower<double, int>(y, x) << endl; // Optimal method.
    
    return 0;
}
