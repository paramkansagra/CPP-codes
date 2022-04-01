#include <iostream>

using namespace std;

int bin(int n,int mult,int ans){
    if(n == 0){
        return ans;
    }
    
    if(n&1){
        ans = ans + mult;
    }
    n = n>>1;

    return bin(n,mult*10,ans);
}

int main(){

    int n;
    cin>>n;

    int binary = bin(n,1,0);
    cout<<binary<<endl;

    return 0;
}