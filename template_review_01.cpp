#include <iostream>
#include <string>
using namespace std;
// A contribution by Wael Assaf.

template<class T>
void Print(T value) {
    std::cout << value << endl;
}


int main()
{
    
    Print(100);
    Print("Wael");
    Print(100.33);
    

    return 0;
}
