#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cout<<"input row and col ";
    cin>>n>>m;

    int arr[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    for(int j=0;j<m;j++){
        int count = 0;
        for(int i=0;i<n;i++){
            count += arr[i][j];
        }
        cout<<count<<" ";
    }cout<<endl;

    return 0;
}