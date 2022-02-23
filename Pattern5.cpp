#include <bits/stdc++.h>

using namespace std;

int main(){
    int i,j,n,count;
    cin>>n;

    cout<<endl;

    i=1;
    while(i<=n){
        j=1;
        while(j<=i-1){
            cout<<" ";
            j++;
        }
        j=1;
        while(j<=n-i+1){
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
        while(j<=i-1){
            cout<<" ";
            j++;
        }
        j=1;
        while(j<=n-i+1){
            cout<<i; 
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
            cout<<' ';
            j++;
        }
        j=1;
        while(j<=i){
            cout<<i;
            j++;
        }
        cout<<endl;
        i++;
    }

    cout<<endl;

    i=1;
    while(i<=n){
        j=1;
        while(j<=i-1){
            cout<<" ";
            j++;
        }
        j=i;
        while(j<=n){
            cout<<j;
            j++;
        }
        cout<<endl;
        i++;
    }

    cout<<endl;

    i=1;
    count = 1;

    while(i<=n){
        j=1;
        while(j<=n-i){
            cout<<" ";
            j++;
        }
        j=1;
        while(j<=i){
            cout<<count;
            count++;
            j++;
        }
        i++;
        cout<<endl;
    }

    cout<<endl;

    i=1;
    while(i<=n){
        j=1;
        while(j<=n-i){
            cout<<" ";
            j++;
        }
        j=i;
        while(j>=1){
            cout<<j;
            j--;
        }
        j=2;
        while(j<=i){
            cout<<j;
            j++;
        }
        j=1;
        while(j<=n-i){
            cout<<" ";
            j++;
        }

        i++;
        cout<<endl;
    }

    cout<<endl;

    return 0;

}