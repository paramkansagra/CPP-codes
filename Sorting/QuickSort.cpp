#include <bits/stdc++.h>

using namespace std;

int partitionArray(int* arr,int start,int end){
    
    // the first element
    int pivot = arr[start];
    
    // count kinte number chote hai
    int cnt = 0;
    for(int i=start+1;i<=end;i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }

    // place pivot at right position
    int pivotIndex = start + cnt;
    swap(arr[pivotIndex],arr[start]);

    // left and right part swapping
    int i = start;
    int j = end;

    while(i<pivotIndex && j>pivotIndex){
        while (arr[i]<=arr[pivotIndex]){
            i++;
        }
        while (arr[j]>arr[pivotIndex]){
            j--;
        }
        if(arr[i]>arr[pivotIndex] && arr[j]<arr[pivotIndex]){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quickSort(int* arr,int start,int end){

    if(start>=end){
        return ;
    }

    int p = partitionArray(arr,start,end);
    
    // quicksort left
    quickSort(arr,start,p-1);

    // quickSort right
    quickSort(arr,p+1,end);

}

int main(){
    int n;
    cout<<"input n ";
    cin>>n;

    // create a dynamic array
    int* arr = new int[n];

    // taking input of the array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    quickSort(arr,0,n-1);

    // giving output of the array
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    // deleting the dynamic array
    delete []arr;

    return 0;
}