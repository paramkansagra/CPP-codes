#include <bits/stdc++.h>

using namespace std;

int findPivot(int arr[],int n){
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;
    while(start<end){
        if(arr[mid]>=arr[0]){ // doing this as the mid-1 element maybe very 
            start = mid+1;   // big so checking the 0th element
        }
        else{
            end = mid;
        }
        mid = start + (end-start)/2;
    }
    return start;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<findPivot(arr,n)<<endl;

    return 0;
}