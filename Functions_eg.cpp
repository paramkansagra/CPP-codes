#include <bits/stdc++.h>

using namespace std;

bool isEven(int a){
    if(a&1){
        return false;
    }
    else{
        return true;
    }
}

int factorial(int n){
    int ans = 1;
    for(int i=1;i<=n;i++){
        ans *= i;
    }
    return ans;
}

int nCr(int n,int r){
    int numerator = factorial(n);
    int denominator = factorial(n-r)*factorial(r);
    return numerator/denominator;
}

void printCounting(int n){
    for(int i=1;i<=n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
}

bool checkPrime(int n){
    for(int i=2;i<n;i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int main(){

    int a;
    cout<<"input the number if even odd"<<endl;
    cin>>a;
    if(isEven(a)){
        cout<<"it is even"<<endl;
    }
    else{
        cout<<"it is odd"<<endl;
    }

    int n,r;
    cout<<"input n and r"<<endl;
    cin>>n>>r;
    cout<<nCr(n,r)<<endl;

    cout<<"till where to count?"<<endl;
    cin>>n;
    printCounting(n);

    cout<<"input the number to check if prime or not"<<endl;
    cin>>n;
    if(checkPrime(n)){
        cout<<"it is prime"<<endl;
    }
    else{
        cout<<"it is not prime"<<endl;
    }

    return 0;
}