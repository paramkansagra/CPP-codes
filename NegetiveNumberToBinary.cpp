#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    bool flag = false;
    int f;
    if(n<0){
        flag = true;
        f = 0-n;
    }

    int ans=0,i=0;

    while(f!=0){
        int bit = f&1;
        ans = (bit*pow(10,i))+ans;
        f = f>>1;
        i++;
    }

    cout<<ans+1;

    return 0;
}