#include <bits/stdc++.h>

using namespace std;

string reverseString(string s,int pos){
    if(pos<s.length()/2){
        swap(s[pos],s[s.length()-pos-1]);
        return reverseString(s,++pos);
    }
    return s;
}

int main(){
    string s;
    cout<<"input the string ";
    cin>>s;

    int pos = 0;
    cout<<"the reverse of the string is "<<reverseString(s,pos)<<endl;

    return 0;
}