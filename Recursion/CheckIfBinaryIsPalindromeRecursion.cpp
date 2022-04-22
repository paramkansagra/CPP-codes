#include <bits/stdc++.h>

using namespace std;

string binary(long long n){
    string s = "";
    while(n>0){
        s.push_back(n&1);
        n = n>>1;
    }
    return s;
}

bool checkPalindrome(string bin,int i,int j){
    if(i<j){
        if(bin[i] != bin[j]){
            return false;
        }
        return checkPalindrome(bin,++i,--j);
    }
    return true;
}

int main(){
    long long n;
    cout<<"input the number n ";
    cin>>n;

    string bin = binary(n);

    if(checkPalindrome(bin,0,bin.length()-1)){
        cout<<"it is a palindrome"<<endl;
    }
    else{
        cout<<"it is not a palindrome"<<endl;
    }

    return 0;
}