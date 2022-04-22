#include <bits/stdc++.h>

using namespace std;

bool checkPalindrome(string s,int pos){
    if(pos<s.length()/2){
        if(s[pos] == s[s.length()-pos-1]){
            pos++;
            return checkPalindrome(s,pos);
        }
        else{
            return false;
        }
    }
    else{
    return true;
    }
}

int main(){
    string s;
    cout<<"input the string ";
    cin>>s;

    if(checkPalindrome(s,0)){
        cout<<"it is a palindrome"<<endl;
    }
    else{
        cout<<"it is not a palindrome"<<endl;
    }

    return 0;
}