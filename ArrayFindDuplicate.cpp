#include <bits/stdc++.h>

using namespace std;

void findDuplicate(int arr[],int n){
    int found[n];
    for(int i=0;i<n;i++){
        int count=0;
        bool present = 0;
        for(int j=0;j<n;j++){
           if(arr[i] == arr[j]) count++;
        }
        for(int j=0;j<n;j++){
            if(arr[i] == found[j]){
                present = 1;
            }
        }
        if(count>1 && present == 0){
            found[i]=arr[i];
            cout<<arr[i]<<endl;
        }
    }
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    findDuplicate(arr,n);

    return 0;
}