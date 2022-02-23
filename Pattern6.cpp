#include <bits/stdc++.h>

using namespace std;

int main(){
    int i,j,n;
    
    cin>>n;
    
    cout<<endl;

    i=1;
    while(i<=n){
        j=1;
        while(j<=n-i+1){
            cout<<j;
            j++;
        }
        j=1;
        while(j<=(i-1)*2){
            cout<<"*";
            j++;
        }
        j=n-i+1;
        while(j>=1){
            cout<<j;
            j--;
        }
        cout<<endl;
        i++;
    }

    return 0;
}