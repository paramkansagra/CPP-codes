#include <bits/stdc++.h>

using namespace std;

void insersionSort(int* arr,int n,int start){
    if(start == n){
        return ;
    }

    int temp = arr[start];
    int j = start-1;
    for(;j>=0;j--){
        if(arr[j]>temp){
            arr[j+1] = arr[j]; // peeche le ke jao
        }
        else{
            break;
        }
    }
    arr[j+1] = temp;

    insersionSort(arr,n,++start);
}

int main(){
    int n;
    cout<<"input n ";
    cin>>n;

    // making the array
    int* arr = new int[n];

    // input the array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    insersionSort(arr,n,1);

    // output the array
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    // delete the array
    delete []arr;

    return 0;
}