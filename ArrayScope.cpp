#include <bits/stdc++.h>

using namespace std;

void update(int arr[],int n){
    arr[n-1] = 69;
    arr[0] = 420;
}

int main(){
    int arr[3] = {1,2,3};
    update(arr,3);
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}