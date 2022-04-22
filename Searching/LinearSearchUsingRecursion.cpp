#include <bits/stdc++.h>

using namespace std;

int linearSearch(int* arr,int n,int target,int pos){
    if(pos<n){
        if(arr[pos] == target){
            return pos;
        }
        else{
            pos++;
            return linearSearch(arr,n,target,pos);
        }
    }
    else{
        return -1;
    }
}

int main(){
    int n;
    cout<<"input the number of elements in the array ";
    cin>>n;

    // making a dynamic array
    int* arr = new int[n];

    // taking input of the array
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int target;
    cout<<"input the target ";
    cin>>target;

    int pos = 0;
    int ans = linearSearch(arr,n,target,pos);
    if(ans != -1){
        cout<<"target is present at "<<ans;
    }
    else{
        cout<<"target is absent"<<endl;
    }

    // clean up the array
    delete []arr;

    return 0;
}