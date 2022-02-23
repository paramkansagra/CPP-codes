#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,sum=0,a=0,b=1;
    cin>>n;

    cout<<endl;

    // syntax is for(initialization;condition;updation){body}

    for(int i=1;i<=n;i++){
        sum+=i;
    }
     
    cout<<sum<<endl;

    cout<<endl;

    // fibbionaci series

    for(int i=1;i<=n;i++){
        cout<<a<<endl;
        int temp = b;
        b += a;
        a = temp;
    }

    cout<<endl;

    // prime number

    bool flag = false;

    for(int i=2;i<n;i++){
        if(n%i == 0){
            cout<<"Not a prime number"<<endl;
            flag = true;
            break;
        }
    }
    if(not flag){
        cout<<"It is a prime number"<<endl;
    }

    cout<<endl;

    // understanding the continue keyword

    for(int i=1;i<=3;i++){
        cout<<"HI"<<endl;
        cout<<"Hey"<<endl;
        continue; // this skips the code to the next iteration
        // iske neeche ki cheeze becomes unreachable
        cout<<"reply to kar de"<<endl;
    }

    cout<<endl;

    return 0;
}