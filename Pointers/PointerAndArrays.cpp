#include <bits/stdc++.h>

using namespace std;

int main(){

    // how to get the address of the first element of the array
    // so the first memory address is nothing but the address of the
    // arr like arr represents the first memory address

    int arr[10] = {23,122,41,67};

    cout<<"address of the first memory block is "<<arr<<endl;
    cout<<"address of the first memory block is "<<&arr[0]<<endl;

    cout<<"4th "<< *arr <<endl; // gives out the value at the first memory block of arr
    cout<<"5th "<< *arr + 1 <<endl; // gives out the value at the first memory block of arr + 1
    cout<<"6th "<< *(arr + 1) <<endl; // gives out the value at the second memory block of the arr
    cout<<"7th "<< *(arr) + 1 <<endl; // gives out the first block + 1    
    cout<<"8th "<< *(arr + 2)<<endl; // gives out the second block
    cout<<"9th "<< arr[2]<<endl; // gives out the second block
    cout<<"10th "<<arr[3]<<endl;
    cout<<"11th "<<3[arr]<<endl;
    cout<<"12th "<<*(arr+3)<<endl;

    // arr[i] = *(arr + i) --> i[arr] = *(i + arr)

    int temp[10];
    cout<<sizeof(temp)<<endl;
    int *ptr = &temp[0];
    cout<<sizeof(*ptr)<<endl;

    int array[20] = {0};
    cout<<&array<<endl;
    cout<<array<<endl;
    cout<<&(array[0])<<endl;

    int *p = &array[0];
    cout<<p<<endl;
    cout<<&p<<endl;

    p=p+1;
    cout<<p<<endl;

    return 0;
}