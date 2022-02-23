#include <bits/stdc++.h>

using namespace std;

int main(){
    int row;
    cout<<"input the number of rows in the array ";
    cin>>row;

    // making the main row array
    int** array = new int*[row];

    // making a data array for storing how many cols
    int* data = new int[row];

    // making the actual 2d array
    for(int i=0;i<row;i++){
        // taking input of the number of cols
        int col;
        cout<<"input the number of cols in the row "<<i+1<<" ";
        cin>>col;
        // appending in the data for keeping a tab
        data[i] = col;
        // making the actual 2 d array
        array[i] = new int[col];
    }

    cout<<"input the elements "<<endl;

    // taking input of the array
    for(int i=0;i<row;i++){
        cout<<"input the elements for the row "<<i+1<<endl;
        for(int j=0;j<data[i];j++){
            cin>>array[i][j];
        }
    }

    cout<<endl;

    // printing the array
    for(int i=0;i<row;i++){
        for(int j=0;j<data[i];j++){
            cout<<array[i][j]<<" ";
        }cout<<endl;
    }

    // deleting the array
    for(int i=0;i<row;i++){
        delete []array[i];
    }

    delete []array;
    delete []data;

    return 0;
}