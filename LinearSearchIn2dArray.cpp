#include <bits/stdc++.h>

using namespace std;

bool isPresent(int arr[][3],int target,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == target){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n=3,m=3;

    int arr[3][3];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }

    int target;
    cout<<"input target ";
    cin>>target;

    if(isPresent(arr,target,n,m)){
        cout<<target<<" is present"<<endl;
    }
    else{
        cout<<target<<" is not present"<<endl;
    }

    return 0;
}