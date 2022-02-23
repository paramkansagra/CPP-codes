#include <bits/stdc++.h>

using namespace std;

void printNumber(int n){
    if(n == 0){
        cout<<endl;
        return ;
    }
    cout<<n<<" ";
    printNumber(n-1);
}

int main(){

    int n;
    cout<<"input the number n ";
    cin>>n;

    printNumber(n);

    return 0;
}