#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j=i;j>0;j--){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    int i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout<<i-j+1<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }

    cout<<endl;

    i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            char ch = 'A'+i-1;
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }

    cout<<endl;

    i = 1;
    while(i<=n){
        int j=1;
        while(j<=n){
            char ch = 'A'+j-1;
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }

    cout<<endl;

    i =1;
    int count = 1;
    while(i<=n){
        int j=1;
        while(j<=n){
            char ch = 'A'+count-1;
            cout<<ch<<" ";
            j++;
            count++;
        }
        cout<<endl;
        i++;
    }

    cout<<endl;

    i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            char ch = 'A'+i+j-2;
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }

    cout<<endl;

    return 0;
}