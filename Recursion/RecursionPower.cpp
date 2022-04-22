#include <bits/stdc++.h>

using namespace std;

int power(int a,int b){
    if(b == 0){
        return 1;
    }
    return a * power(a,b-1);
}

int main(){

    int a,b;
    cout<<"input a and b ";
    cin>>a>>b;

    cout<<"power of a^b is "<<power(a,b)<<endl;

    return 0;
}