#include <bits/stdc++.h>

using namespace std;

int main(){

    // pointer to int is created and pointing to grarbage address
    // int *p; bad practice 

    // if we have nothing to point at do this
    // int *p = 0; // this creates a null pointer

    // cout<<*p<<endl; causes segmentation fault

    int i = 5;
    int *p = &i;

    cout<<"address of i "<<p<<endl;
    cout<<"value of i is "<<*p<<endl;

    // or else

    int *pnew = 0;
    pnew = &i;

    // pnew and p are the same thing just diffrent way of implementations


    int num = 5;
    int a = num;
    a++;
    cout<<"value of num is "<<num<<endl;

    // lets do this with pointers

    int x = 5;
    int *ptr = &x;
    int newptr = *ptr;
    newptr++;
    // kuch nahi hua
    cout<<"value of x is "<<x<<endl;

    (*ptr)++;
    cout<<"value of x is "<<x<<endl;
    // value of x increases as we increased the value at the pointer


    // coping a pointer
    int *newnewptr = ptr;
    cout<<"*newnewprt "<<*newnewptr<<endl;
    cout<<"*ptr "<<*ptr<<endl;

    return 0;

}