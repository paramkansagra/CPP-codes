#include <bits/stdc++.h>

using namespace std;

void reverseArray(int arr[],int n){
    for(int i=0;i<n/2;i++){
        int start=arr[i];
        int end = arr[n-i-1];
        arr[i]=end;
        arr[n-i-1]=start;
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    reverseArray(arr,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}