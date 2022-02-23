#include <bits/stdc++.h>

using namespace std;

void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
        printArr(arr,n);
    }
}

int main(){
    
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    bubbleSort(arr,n);
    printArr(arr,n);
}