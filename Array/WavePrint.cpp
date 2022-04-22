#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cout<<"input the row and column ";
    cin>>n>>m;

    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    cout<<endl;

    bool flag = false;
    for(int i=0;i<n;i++){
        if(flag){
            for(int j=0;j<m;j++){
                cout<<arr[i][j]<<" ";
            }cout<<endl;
            flag = false;
        }
        else{
            for(int j=m-1;j>=0;j--){
                cout<<arr[i][j]<<" ";
            }cout<<endl;
            flag = true;
        }
    }
    

    return 0;
}