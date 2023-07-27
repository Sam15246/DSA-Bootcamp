// Q1. Given a pointer to the first character of a (C style) string. Find the length of the string.
#include <iostream>
using namespace std;
int lengthOf(char* firstChar){
    
    int  i = 0, len=0;
    for(;firstChar[i] != '\0';){
        len++;
        i++;
    }
    return len;
}

int main(){
    char *firstChar = "ABSCDE";
    int ans = lengthOf(firstChar);
    cout<<ans;
}

