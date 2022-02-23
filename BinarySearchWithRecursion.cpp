#include <bits/stdc++.h>

using namespace std;

int binarySearch(int* arr,int start,int end,int target){
    if(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]>target){
            end = mid - 1;
            binarySearch(arr,start,end,target);
        }
        else{
            start = mid + 1;
            binarySearch(arr,start,end,target);
        }
    }

    return -1;
}

int main(){

    int n;
    cout<<"input the number of element in the array ";
    cin>>n;

    int* arr = new int[n]; // making a dynamic array

    cout<<"input the array elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int target;
    cout<<"input the target ";
    cin>>target;

    // get the binary search

    int start = 0;
    int end = n-1;

    int ans = binarySearch(arr,start,end,target);
    if(ans != -1){
        cout<<"the position of "<<target<<" is "<<ans<<endl;
    }
    else{
        cout<<"target not present"<<endl;
    }

    // cleaning up the array
    delete []arr;

    return 0;
}