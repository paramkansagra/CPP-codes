#include <bits/stdc++.h>

using namespace std;

int main(){
    // normal implementation of array
    int arr[3] = {1,2,3};
    // implementation of STL array
    array<int,4> a = {1,2,3,4};

    // syntax = array<data type,size> name;
    // you can also initialize it as we do of the normal array

    int size_normal_array = sizeof(arr)/sizeof(int);
    int size_stl_array = a.size();

    // traversing the array

    for(int i=0;i<size_stl_array;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    // how to check the element at a particular pos

    cout<<"element at 2nd index "<<a.at(2)<<endl;

    // check if array is empty or not 
    // it will return a boolen(0/1)

    cout<<"is element empty "<<a.empty()<<endl;

    // which element is present at first pos?

    cout<<"the first element is "<<a.front()<<endl;

    // element present at last pos

    cout<<"the last element is "<<a.back()<<endl;

    // also container operations are allwed

    sort(a.begin(),a.end());

    // if you want to initialize the array then you 
    // can do it using the fill command

    array<int,10> data;
    data.fill(10);

    for(int i=0;i<10;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;

    // you can also do swapping

    swap(a[0],a[3]);
    for(int i=0;i<a.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}