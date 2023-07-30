// Write a C++ program and define the following structures:
#include <iostream>
using namespace std;

struct type1
{
    char x;
    char y;
    int i;
    double d;
};
struct type2
{
    char x;
    double d;
    char y;
    int i;
};
struct type3
{
    char x;
    int i;
    char y;
    double d;
};

// And find the size of each of these structures.

int main()
{
    cout << "\nSize of type 1 = " << sizeof(type1) << " bytes." << endl;
    cout << "Size of type 2 = " << sizeof(type2) << " bytes." << endl;
    cout << "Size of type 3 = " << sizeof(type3) << " bytes." << endl;
}

// Output:
// Size of type 1 = 16 bytes.
// Size of type 2 = 24 bytes.
// Size of type 3 = 24 bytes.


/* Reason -Padding(What is this ? KIY) */
