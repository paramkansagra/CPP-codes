#include <bits/stdc++.h>

using namespace std;

bool isPresent(int arr[],int n,int search){
    bool present = 0;
    for(int i=0;i<n;i++){
        if(search == arr[i]){
            present = 1;
            break;
        }
    }
    return present;
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

    if(isPresent(arr,n,search)){
        cout<<"It is present"<<endl;
    }
    else{
        cout<<"It is not present"<<endl;
    }

    return 0;
}