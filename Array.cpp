#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    
    // declaring an array
    // <obj type> variable name[number of elements];

    int arr[5] = {};
    for(int i=0;i<5;i++){
        arr[i] = 1;
    }

    // accessing a array
    printArray(arr,5);

    int second[3] = {5,3,4};

    printArray(second,3);

    cout<<"Everything is fine"<<endl;

    return 0;
}