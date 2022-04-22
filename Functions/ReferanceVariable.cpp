#include <bits/stdc++.h>

using namespace std;

void update1(int a){
    a++;
}

void update2(int& a){
    a++;
}

// int& func(int a){ // bad practice
//     int num = a;
//     num++;
//     int& ans = num;
//     return ans;
// }

int main(){
    // int i = 5;
    // int& j = i; // creating a reference variable

    // cout<<i<<endl;
    // j++;
    // cout<<i<<endl;
    // i++;
    // cout<<j<<endl;

    int i = 5;
    cout<<"before update1 "<<i<<endl;
    update1(i);
    cout<<"after update1 "<<i<<endl;
    cout<<"before update2 "<<i<<endl;
    update2(i);
    cout<<"after update2 "<<i<<endl;

    //func(i); // lets see if it gives a warning or not
    // gives out a memory error

    

    return 0;
}