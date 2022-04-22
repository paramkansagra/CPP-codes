#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    cout<<endl;

    int i,j,count;

    i=1;
    while(i<=n){
        j=1;
        while(j<=i){
            char ch='A'+i-1;
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }

    cout<<endl;
    
    count = 1;
    i = 1;
    while(i<=n){
        j=1;
        while(j<=i){
            char ch = 'A'+count-1;
            cout<<ch<<' ';
            j += 1;
            count += 1;
        }
        cout<<endl;
        i += 1;
    }

    cout<<endl;
    
    i=1;
    while(i<=n){
        j=1;
        while(j<=i){
            char ch = 'A'+i+j-2;
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }

    cout<<endl;

    i=1;
    while(i<=n){
        j=1;
        while(j<=i){
            char ch = 'A'+n-i+j-1;
            cout<<ch;
            j++;
        }
        cout<<endl;
        i++;
    }

    cout<<endl;

    i=1;
    while(i<=n){
        j=1;
        while(j<=n-i){
            cout<<" ";
            j++;
        }
        j = 1;
        while(j<=i){
            cout<<"*";
            j++;
        }
        cout<<endl;
        i++;
    }

    cout<<endl;

    i=1;
    while(i<=n){
        j=1;
        while(j<=n-i+1){
            cout<<"*";
            j++;
        }
        j=1;
        while(j<=i-1){
            cout<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }

    cout<<endl;

    return 0;
}