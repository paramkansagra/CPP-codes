#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b;
    a = 4;
    b = 6;

    cout<<(a&b)<<endl; // here & is and operator
    cout<<(a|b)<<endl; // here | is or operator
    cout<<(~a)<<endl; // here ~ is the not operator
    cout<<(a^b)<<endl; // here ^ is the xor operator
    
    // left shift and right shift operator
    cout<<(17>>1)<<endl;
    cout<<(17>>2)<<endl;
    cout<<(19<<1)<<endl;
    cout<<(21<<2)<<endl;

    // pre and post increment and decrement

    int i=7;
    cout<<i++<<endl;
    cout<<++i<<endl;
    cout<<i--<<endl;
    cout<<--i<<endl;

    return 0;
}