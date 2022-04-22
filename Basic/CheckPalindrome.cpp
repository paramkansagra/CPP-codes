#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;

    int start = 0;
    int end = s.length()-1;

    bool flag = true;

    while(start<=end){
        if(s[start] != s[end]){
            flag = false;
            break;
        }
        start++;
        end--;
    }

    if(flag){
        cout<<"it is a palindrome"<<endl;
    }
    else{
        cout<<"it is not a palindrome"<<endl;
    }

    return 9;
}