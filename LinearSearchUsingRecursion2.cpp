#include <bits/stdc++.h>

using namespace std;

bool linearSearch(int* arr,int n,int target){
    if(n == 0){
        return false;
    }
    else{
        if(arr[0] == target){
            return true;
        }
        else{
            return linearSearch(arr+1,n-1,target);
        }
    }
}

int main(){
    int n;
    cout<<"input the number of elements ";
    cin>>n;

    // making a dynamic array
    int* arr = new int[n];

    // taking input 
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int target;
    cout<<"input the target ";
    cin>>target;

    // linear search
    if(linearSearch(arr,n,target)){
        cout<<"target is present"<<endl;
    }
    else{
        cout<<"target is absent"<<endl;
    }

    // clean up the array
    delete []arr;

    return 0;
}