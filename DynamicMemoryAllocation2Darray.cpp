#include <bits/stdc++.h>

using namespace std;

int main(){
    
    // taking input of the row and col of the array
    int row,col;
    cout<<"input the row and cols for the matrix ";
    cin>>row>>col;

    // making the dynamic array
    int** arr = new int* [row];

    // creating the array
    for(int i=0;i<row;i++){
        arr[i] = new int[col];
    }
    
    // taking the input of the new array
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }

    cout<<endl;

    // giving out put of the matrix
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }

    // freeing the array because dynamic array
    for(int i=0;i<row;i++){
        delete [] arr[i];
    }

    delete []arr;

    return 0;
}