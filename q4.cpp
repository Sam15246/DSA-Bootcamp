// Q4. Given a pointer to the first element (0,0) of a 2D integer array, return a pointer to its last element (m-1,n-1). 
// Where m & n are integers and denote the no. of rows and no. of cols in the 2D array.

#include <iostream>
using namespace std;

int* lastEl(int* firstEl, int m,int n){

    for(int i= 0; i < m; i++){
        for(int j = 0;j<n;j++){
            firstEl++;
        }
    }
    return firstEl - 1;
}
