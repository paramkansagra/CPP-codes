#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=1;j<=n;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    for(int i=0;i<n;i++){
        for(int j=n;j>0;j--){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    int i=1;
    for(int j=0;j<n;j++){
        for(int k=0;k<n;k++){
            cout<<i<<" ";
            i++;
        }
        cout<<endl;
    }
    
    return 0;
}