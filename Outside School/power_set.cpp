// C++ Implementation to Generate Power Sets
// Concept can be twisted to Generate Truth Tables.
// A contribution by Wael Assaf.
#include <iostream> 
#include <math.h> 
using namespace std; 

void PowerSet(char *set, int s)
{ 
	unsigned int power = pow(2, s); 
	for(int i = 0; i < power; i++) {
    	for(int j = 0; j < s; j++) { 
    		if(i & (1 << j)) 
    			cout << set[j]; 
    	}
	    cout << endl; 
    } 
} 

int main() 
{
	char set[] = {'A','I','U'}; 
	PowerSet(set, 3); 
	return 0; 
}

