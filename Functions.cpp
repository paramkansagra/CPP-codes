#include <bits/stdc++.h>

using namespace std;

// function return Name of function (variable names){code}
int power(int a,int b){
    int ans = 1;
    for(int i=0;i<b;i++){
        ans *= a;
    }
    return ans;
}

int main(){
    
    // pow(a,b)

    int a,b;
    cin>>a>>b;

    cout<<power(a,b)<<endl;

    return 0;
}