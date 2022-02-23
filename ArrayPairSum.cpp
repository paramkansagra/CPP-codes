#include <bits/stdc++.h>

using namespace std;

void pairSum(int arr[],int n,int s){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j] == s){
                cout<<arr[i]<<" "<<arr[j]<<endl;
            }
        }
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int s;
    cin>>s;

    pairSum(arr,n,s);
    return 0;
}