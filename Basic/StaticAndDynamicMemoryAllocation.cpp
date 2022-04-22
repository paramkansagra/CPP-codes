#include <bits/stdc++.h>

using namespace std;

int getSum(int* arr,int n){
    // finding the sum of the array
    int count = 0;
    for(int i=0;i<n;i++){
        count += arr[i];
    }
    return count;
}

int main(){
    // taking input from user
    int n;
    cin>>n;
    
    // making a dynamic array
    int* arr = new int[n];

    // taking input in the array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int sum = getSum(arr,n);
    cout<<"the sum of the array is "<<sum<<endl;

    return 0;
}