#include <bits/stdc++.h>

using namespace std;

void update(int **ptr2){
    //ptr2 = ptr2 + 1; // no change
    //*ptr2 = *ptr2 + 1; // change seen
    **ptr2 = **ptr2 + 1; // change seen
}

int main(){

    int i = 5;
    int* ptr1 = &i; // single pointer
    int** ptr2 = &ptr1; // double pointer

    cout<<endl;

    // lets print the address p is pointing to
    cout<< "ptr 1 is pointing to " <<ptr1 <<endl;
    cout<< "address of ptr 1 " << &ptr1 << endl; // printing the address of ptr 1
    cout<< "value the address holds to which ptr1 is pointing to " << *ptr1 <<endl; // printing the value p is pointing to

    cout<< "ptr 2 is pointing to " <<ptr2 <<endl; // printing the address ptr2 is pointing to
    cout<< "the address of ptr 2 is "<< &ptr2 << endl; // printing the address of ptr 2
    cout<< "value of the address ptr 2 is pointing to " <<*ptr2 <<endl; // printing the value address of ptr2 is pointing to
    cout<< "value the address ptr 1 is pointing to thru ptr 2 " <<**ptr2 <<endl; // printing the value the address ptr1 is pointing thru ptr2 

    cout<< "address of i " << &i << endl;
    cout<< "address ptr1 is holding " << ptr1 <<endl;
    cout<< "address ptr2 is pointing to " << *ptr2 <<endl;

    update(ptr2);
    cout<< i <<endl;
    cout << ptr1 << endl;
    cout << ptr2 <<endl;

    cout<<endl;

    return 0;
}