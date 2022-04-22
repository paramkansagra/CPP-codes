#include <bits/stdc++.h>

using namespace std;

string reverseString(string s,int i,int j){
    if(i<j){
        swap(s[i],s[j]);
        return reverseString(s,++i,--j);
    }
    return s;
}

int main(){
    string s;
    cout<<"input the string ";
    cin>>s;

    int i=0;
    int j = s.length()-1;

    cout<<reverseString(s,i,j)<<endl;

    return 0;
}