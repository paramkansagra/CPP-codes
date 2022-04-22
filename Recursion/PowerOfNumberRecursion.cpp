#include<bits/stdc++.h>

using namespace std;

long long power(int a,int b){
    if(b>0){
        return a*power(a,--b);
    }
    return 1;
}

int main(){
    int a;
    int b;

    cout<<"input a and b ";
    cin>>a>>b;

    cout<<power(a,b)<<endl;

    return 0;
}