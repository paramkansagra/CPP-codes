#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[5] = {1,2,3,4,5};
    char ch[6] = "abcde";

    cout<<arr<<endl;
    cout<<ch<<endl;

    // implementation of cout for integer array and char
    // array is diffrent

    char *c = &ch[0];
    cout<<c<<endl; // printed the complete string 
    // this is because the implementation of cout is diffrent

    char s = 'z';
    char *p = &s;
    cout<<p<<endl;
    // kuch bhi print ho raha hai
    // start from address and print till a null char is not found

    return 0;
}