#include <bits/stdc++.h>

using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        bool swapped = false;
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            // as it is already in place
            break;
        }
    }

    // print the array
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    bubbleSort(arr,n);

    return 0;
}