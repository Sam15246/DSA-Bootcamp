// Q2. Find the sizes of the following data types using pointer arithmetics:
// •bool
// •char
// •int
// •double
// •long long
// •long double
#include <iostream>
using namespace std;

int main() {
    bool a;
    char c;
    int i;
    double d;
    long long ll;
    long double ld;

    bool *pb = &a;
    char *pc = &c;
    int *pi = &i;
    double *pd = &d;
    long long *pll = &ll;
    long double *pld = &ld;

    cout << "Size of bool: " << (char*)(pb + 1) - (char*)pb << " bytes" << endl;
    cout << "Size of char: " << (char*)(pc + 1) - (char*)pc << " bytes" << endl;
    cout << "Size of int: " << (char*)(pi + 1) - (char*)pi << " bytes" << endl;
    cout << "Size of double: " << (char*)(pd + 1) - (char*)pd << " bytes" << endl;
    cout << "Size of long long: " << (char*)(pll + 1) - (char*)pll << " bytes" << endl;
    cout << "Size of long double: " << (char*)(pld + 1) - (char*)pld << " bytes" << endl;

    return 0;
}
