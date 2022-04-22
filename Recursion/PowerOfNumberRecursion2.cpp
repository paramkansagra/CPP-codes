#include <bits/stdc++.h>

using namespace std;

long long power(int a,int b){
    // base condition
    if(b == 0){
        return 1;
    }

    if(b == 1){
        return a;
    }

    // power = a^b = (a^(b/2))*(a^(b/2))

    if(b%2 == 0){
        return power(a,b/2)*power(a,b/2);
    }
    else{
        return a * power(a,(b-1)/2) * power(a,(b-1)/2);
    }
}

int main(){
    int a,b;
    cout<<"input a and b ";
    cin>>a>>b;

    cout<<power(a,b)<<endl;

    return 0;
}