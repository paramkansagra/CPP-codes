#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[],int n,int start,int end,int search){
    if(start<=end){
        int mid = start + ((end-start)/2);
        if(arr[mid] == search){
            return mid;
        }
        else if(arr[mid]>search){
            return binarySearch(arr,n,start,mid-1,search);
        }
        else{
            return binarySearch(arr,n,mid+1,end,search);
        }
    }
    else{
        return -1;
    }
}


int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int search;
    cin>>search;

    int start = 0,end=n-1;

    cout<<binarySearch(arr,n,start,end,search)<<endl;

    return 0;
}