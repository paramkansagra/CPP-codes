#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,hundred,fifty,tens,ones;
    cin>>n;

    switch(true){
        case true:
            hundred = n/100;
            n = n%100;
            fifty = n/50;
            n = n%50;
            tens = n/10;
            n = n%10;
            ones = n;
    }
    cout<<hundred<<" "<<fifty<<" "<<tens<<" "<<ones<<endl;

    return 0;
}