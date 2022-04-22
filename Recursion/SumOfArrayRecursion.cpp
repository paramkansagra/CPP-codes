#include <bits/stdc++.h>

using namespace std;

int sumArray(int* arr,int n,int pos){
    if(pos == n-1){
        return arr[pos];
    }
    else{
        return arr[pos] + sumArray(arr,n,++pos);
    }
}

int main(){

    int n;
    cout<<"input the number of elements ";
    cin>>n;

    // making a dynamic array
    int* arr = new int[n];

    // taking input of the array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int pos = 0;
    cout<<"the sum of the array is "<<sumArray(arr,n,pos)<<endl;

    // cleaning the array
    delete []arr;

    return 0;
}