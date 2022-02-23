#include <bits/stdc++.h>

using namespace std;

int main(){
    // syntax of switch case (no float or string cases allowed)
    // switch (experession){
    //     case const1(int/char) : code
    //     case const2 : code
    //     case const3 : code
    //     .
    //     .
    //     .
    //     default: if nothing happens
    //      code
    // }

    int ch = 'a';
    switch (ch)
    {
    case 1:
        cout<<"This is case 1"<<endl;
        break;
    
    case '1':
        cout<<"This is character 1"<<endl;
        break;

    default: // this is not mandatory if present good else okie
        cout<<"This is the default case"<<endl;
        break;
    }

    // in a infinite loop if there is a switch statement how to exit it??
    // we can do it using exit() this terminates the whole programme
    // then we can give codes like exit(0) exit(1) and all just see what happens

    ch = '1';
    switch (ch)
    {
    case 1:
        cout<<"This is case 1"<<endl;
        exit(0);
        break;
    
    case '1':
        cout<<"This is character 1"<<endl;
        exit(1);
        break;

    default: // this is not mandatory if present good else okie
        cout<<"This is the default case"<<endl;
        exit(2);
        break;
    }

    // you cannot use continue in case of switch
    // it is not valid

    return 0;
}