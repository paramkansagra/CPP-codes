#include <bits/stdc++.h>

using namespace std;

void merge(int* arr,int start,int end){

    int mid = start + (end-start)/2;

    int len1 = mid-start+1;
    int len2 = end-mid;

    int* first = new int[len1];
    int* second = new int[len2];

    // copy the arrays
    int k = start;
    for(int i=0;i<len1;i++){
        first[i] = arr[k];
        k++;
    }

    k = mid+1;
    for(int j=0;j<len2;j++){
        second[j] = arr[k];
        k++;
    }

    // two pointer approch
    int index1 = 0;
    int index2 = 0;
    int i = start;

    while(index1<len1 && index2<len2){
        if(first[index1]<second[index2]){
            arr[i++] = first[index1++];
        }
        else{
            arr[i++] = second[index2++];
        }
    }

    // if any elements left
    while(index1<len1){
        arr[i++] = first[index1++];
    }
    while(index2<len2){
        arr[i++] = second[index2++];
    }
}

void mergeSort(int* arr,int start,int end){

    // base case
    if(start>=end){
        return ;
    }

    int mid = start + (end-start)/2;
    // left part
    mergeSort(arr,start,mid);

    // right part
    mergeSort(arr,mid+1,end);

    // merge the array
    merge(arr,start,end);
}

int main(){
    int n;
    cout<<"input n ";
    cin>>n;

    // make dynamic array
    int* arr = new int[n];

    // take input of the array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    mergeSort(arr,0,n-1);

    // output the array
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }cout<<endl;

    // delete array
    delete []arr;

    return 0;
}