// Q3. Given to pointer to the last element of a (0 indexed) linear integer array, and an integer n denoting the size of the array. 
// Reverse the array, and return nothing.

#include <iostream>
using namespace std;
void reverse(int* lastElement, int n){

    int* firstElement = lastElement - (n - 1); 

    while(firstElement < lastElement){

        int temp = *firstElement;
        *firstElement = *lastElement;
        *lastElement = temp;

        firstElement++;
        lastElement--;
    }
}
