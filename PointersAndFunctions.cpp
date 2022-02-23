#include <bits/stdc++.h>

using namespace std;

void printValue(int *p){
    cout<<p<<endl; // address it is pointing to
    cout<<&p<<endl; // address of pointer
    cout<<*p<<endl; // value pointer is pointing to
}   

void update(int *p){
    // p = p + 1; // increasing the value of pointer
    // we cant play with the pointer like this

    (*p)++; // increase the value by 1
}

int getSum(int arr[],int n){
    // here insted of the array getting passed the
    // pointer of the array is being passed
    // if we remember then if we go outside the size of arr
    // then we get garbage value rt this is due to that
    // we read the value of a garbage value which is outside
    // the array


    cout<<"size of arr "<<sizeof(arr)<<endl;

    int count = 0;
    for(int i=0;i<n;i++){
        count+= arr[i];
    }
    return count;
}

int main(){

    int value = 5;
    int *p = &value;

    cout<<"before p was updated" << endl;
    printValue(p);

    cout<<"after p was updated" << endl;
    update(p);
    printValue(p);

    int arr[5] = {1,2,3,4,5};
    cout<<"the sum is "<<getSum(arr,5)<<endl;

    return 0;
}