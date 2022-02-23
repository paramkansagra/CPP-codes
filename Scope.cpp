#include <bits/stdc++.h>

using namespace std;

int main(){
    int a=3;
    cout<<a<<endl;

    // in a big block({} these parentheses) you cant make variables of same name
    // also you cant change the type of the variable once declared
    // you need to either change variable name or use something else
    
    if(true){
        int a = 5; // makeing a variable in local scope
        cout<<a<<endl;
    }

    if(true){
        cout<<a<<endl; // as variable not make in local scope it 
        // will take the global a
    }

    int i=8;
    cout<<i<<endl;

    for(int i=1;i<=8;i++){
        cout<<i<<endl; //we are explicitly making a variable i 
        // so the for loop will only use this i not the global i
    }

    for(;i<=8;i++){
        cout<<i<<endl; // as we are not defining i here
        // it will search for global i and use it
    }

    return 0;
}   