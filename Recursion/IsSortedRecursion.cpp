#include <bits/stdc++.h>

using namespace std;

bool isSorted(int* arr,int n,int pos){
    if(pos != n-1){
        if(arr[pos]>arr[pos+1]){
            return false;
        }
        else{
            pos++;
            isSorted(arr,n,pos);
        }
    }
    else{
        return true;
    }
}

int main(){

    int n;
    cout<<"input the number of elements ";
    cin>>n;

    int* arr = new int[n]; // making a dynamic array;

    // taking the input
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int pos = 0;

    if(isSorted(arr,n,pos)){
        cout<<"the array is sorted"<<endl;
    }
    else{
        cout<<"the array is not sorted"<<endl;
    }

    // cleaning up the array
    delete []arr;
    
    return 0;
}