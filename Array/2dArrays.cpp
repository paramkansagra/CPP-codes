#include <bits/stdc++.h>

using namespace std;

int main(){
    // create a 2 d array
    // syntax
    // dataType VarName[row][col] like a box
    int arr_row[3][3];
    int arr_col[3][3];

    // taking input row wise
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr_row[i][j];
        }
    }

    cout<<endl;

    // taking input col wise
    for(int j=0;j<3;j++){
        for(int i=0;i<3;i++){
            cin>>arr_col[i][j];
        }
    }

    cout<<endl;

    // giving output row wise
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr_row[i][j]<<" ";
        }cout<<endl;
    }

    cout<<endl;

    // giving output col wise
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr_col[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}