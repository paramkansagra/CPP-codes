#include <bits/stdc++.h>

using namespace std;

int main(){
    int num = 5;

    cout<<num<<endl; // printing the thing placed at address of num

    // lets print the address of num using address of Operator(&)
    cout<<"the address of num is "<<&num<<endl;

    // lets come to pointers
    // whats the need of pointers??
    // address ko store karne ka kam pointer karta hai

    // creating a pointer
    int *ptr = &num;

    cout<<"Pointer address "<<ptr<<endl;
    cout<<"value at pointer address "<<*ptr<<endl;
    // star or * is a dereference value it gives out the value at that pointer address


    // what is int *p
    // it means the variable p is  a pointer pointing to a int value

    // ALSO THE POINTER DATA TYPE SHOULD BE SAME AS THE VALUE IT IS POINTING TO
    
    // if we remember then when we pass value to function it is like a copy
    // and we dont change value in the actual variable but what if we want to??

    double d = 4.32;
    double *ptr2 = &d;

    cout<<"address of ptr2 "<<ptr2<<endl;
    cout<<"value at address stored by ptr2 is "<<*ptr2<<endl;
    
    cout<<"size of double is "<<sizeof(double)<<endl;
    cout<<"size of pointer is "<<sizeof(ptr2)<<endl;
    // size of pointer is always 8


    return 0;
}