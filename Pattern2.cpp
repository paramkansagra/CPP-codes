#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"*"<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    int count=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            cout<<count<<" ";
            count++;
        }
        cout<<endl;
    }

    cout<<endl;
    
    for(int i=1;i<=n;i++){
        for(int j=i;j<i*2;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}