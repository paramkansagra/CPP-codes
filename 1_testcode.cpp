#include <bits/stdc++.h>

using namespace std;

int main(){

    string n;
    cin>>n;
    reverse(n.begin(),n.end());

    string first = "";
    string second = "";
    for(int i=0;i<n.length();i++){
        if(i%2 == 0){
            first.push_back(n[i]);
        }
        else{
            second.push_back(n[i]);
        }
    }
    cout<<first<<endl;
    cout<<second<<endl;

    return 0;
}