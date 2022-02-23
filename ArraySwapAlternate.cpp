#include <bits/stdc++.h>

using namespace std;

void swapAlternate(int arr[],int n){
    for(int i=0;i<(n/2)*2;i+=2){
        int first=arr[i];
        int second = arr[i+1];
        arr[i] = second;
        arr[i+1] = first;
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    swapAlternate(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}