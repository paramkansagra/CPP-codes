#include <bits/stdc++.h>

using namespace std;

int isGreaterFunction(int a,int b){ // takes a performance hit
    if(a>b) return a;
    else return b;
}

inline int isGreaterInline(int& a,int& b){
    return (a>b) ? a:b;
}

int main(){
    int a = 2,b = 3;
    int ans = isGreaterInline(a,b); // time consuming if want to change
    cout<<ans;

    a += 2;
    int ans2 = isGreaterInline(a,b);
    cout<<ans;

    return 0;
}