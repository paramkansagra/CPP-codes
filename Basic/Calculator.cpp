#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b;
    char op;

    cin>>a>>b;
    cin>>op;

    switch(op){
        case '*':
            cout<<a*b<<endl;
            break;
        case '/':
            cout<<a/b<<endl;
            break;
        case '+':
            cout<<a+b<<endl;
            break;
        case '-':
            cout<<a-b<<endl;
            break;
        case '%':
            cout<<a%b<<endl;
            break;
        case '^':
            cout<<pow(a,b)<<endl;
            break;
        case '>':
            if(a>b) cout<<true<<endl;
            else cout<<false<<endl;
            break;
        case '<':
            if(a<b) cout<<true<<endl;
            else cout<<false<<endl;
            break;
        default:
            cout<<"No operations matching"<<endl;
            break;
    }

    return 0;
}