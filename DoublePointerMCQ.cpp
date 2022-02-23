#include <bits/stdc++.h>

using namespace std;

// void update(int *p){
//     *p = (*p)  *  2;
// }

// void fun(int arr[]) {
//     cout << arr[0] << " ";
// }

// void increment(int **p){
//     ++(**p);
// }

void update(int *p){
    int a = 70;
    p = &a;
    *p = (*p) * (*p);
}


int main(){

    // int first = 8;
    // int second = 18;
    // int *ptr = &second;
    // *ptr = 9;
    // cout  << first << " " << second << endl; 

    // int first = 6;
    // int *p = &first;
    // int *q = p;
    // (*q)++;
    // cout << first  << endl;

    // int first = 8;
    // int *p = &first;
    // cout << (*p)++ << " ";
    // cout << first << endl;

    // int *p = 0;
    // int first = 110;
    // *p = first;
    // cout << *p << endl;

    // int first = 8;
    // int second = 11;
    // int *third = &second; 
    // first = *third;
    // *third = *third + 2;
    // cout  << first << "  " << second << endl;

    // float f = 12.5;
    // float p = 21.5;
    // float* ptr = &f;
    // (*ptr)++;
    // *ptr = p;
    // cout << *ptr << " " << f << " " << p << endl;

    // int arr[5];
    // int *ptr;
    // cout << sizeof(arr) << " " << sizeof(ptr) << endl;

    // int arr[] = {11, 21, 13, 14};
    // cout << *(arr) << " " << *(arr+1) << endl;

    // int arr[6] = {11, 12, 31};
    // cout << arr << " " << &arr << endl;

    // int arr[6] = {11, 21, 13};
    // cout << (arr + 1) << endl;

    // int arr[6] = {11, 21, 31};
    // int *p = arr;
    // cout << p[2] << endl;

    // int arr[] = {11, 12, 13, 14, 15};
    // cout << *(arr) << " " << *(arr + 3);

    // int arr[] = {11, 21, 31, 41};
    // int *ptr = arr++;
    // cout << *ptr << endl;

    // char ch = 'a';
    // char* ptr = &ch;
    // ch++;
    // cout << *ptr << endl;

    // char arr[] = "abcde";
    // char *p = &arr[0];
    // cout << p << endl;

    // char arr[] = "abcde";
    // char *p = &arr[0];
    // p++;
    // cout << p << endl;

    // char str[]= "babbar";
    // char *p = str;
    // cout << str[0] << " " << p[0] << endl;

    // int i = 10;
    // update(&i);
    // cout << i << endl;

    // int arr[] = {11, 12, 13, 14};
    // fun(arr + 1);
    // cout << arr[0] << endl;

    // int a = 70;
    // update(&a);
    // cout << a << endl;

    // int first = 10;
    // int *p = &first;
    // int **q = &p;
    // int second = 20;
    // *q = &second;
    // (*p)++;
    // cout << first << " " << second << endl;

    // int first = 110;
    // int *p = &first;
    // int **q = &p;
    // int second = (**q)++ + 9;
    // cout << first << " " << second << endl; 

    // int first = 100;
    // int *p = &first;
    // int **q = &p;
    // int second = ++(**q);
    // int *r = *q;
    // ++(*r);
    // cout << first << " " << second << endl; 

    // int num = 110;
    // int *ptr = &num;
    // increment(&ptr);
    // cout << num << endl;

    // int arr[] = {41, 52, 36, 74};
    // int *p = (arr + 1);
    // cout << *arr + 8;

    // char *p; 
    // char str[] = "pqrstuv";
    // p = str;
    // p += 3;
    // cout << p;

    // char arr[20];
    // int i;
    // for (i = 0; i < 10; i++)
    // {
    //     *(arr + i) = 65 + i;
    // }
    // *(arr + i) = '\0';
    // cout << arr;

    // float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    // float *ptr1 = &arr[0];
    // float *ptr2 = ptr1 + 3;
    // cout << *ptr2 << " ";
    // cout << ptr2 - ptr1;

    return 0;
}