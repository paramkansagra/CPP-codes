#include <bits/stdc++.h>

using namespace std;

void selectionSort(int* arr,int n,int start){
    if(start == n){
        return ;
    }

    // find the min element and place it in the front

    for(int i=start;i<n-1;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[minIndex]>arr[j]){
                minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }

    return selectionSort(arr,n,++start);
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

    selectionSort(arr,n,0);

    // output the array
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    // delete the array
    delete []arr;

    return 0;
}