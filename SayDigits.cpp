#include <bits/stdc++.h>

using namespace std;

void sayDigit(int n){
    if(n == 0){
        cout<<endl;
        return ;
    }

    // making the say
    string arr[10];
    arr[0] = "zero";
    arr[1] = "one";
    arr[2] = "two";
    arr[3] = "three";
    arr[4] = "four";
    arr[5] = "five";
    arr[6] = "six";
    arr[7] = "seven";
    arr[8] = "eight";
    arr[9] = "nine";

    // digit and update
    int digit = n%10;
    n = n / 10;

    // recursive add
    sayDigit(n);

    cout<<arr[digit]<<" "; // recursive call se vapas anne eke vakt print karvao

}

int main(){
    int n;
    cin>>n;
    
    sayDigit(n);

    return 0;
}