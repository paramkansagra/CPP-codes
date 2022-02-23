#include <bits/stdc++.h>

using namespace std;

void ap(){
    int a,d,n;
    cout<<"input the a d and n value"<<endl;
    cin>>a>>d>>n;
    cout<<"value of ap is "<<((a*n)+d)<<endl;
}

int count_set_bits(int a){
    int count = 0;
    while(a!=0){
        if(a&1){
            count += 1;
        }
        a = a>>1;
    }
    return count;
}

void set_bits(){
    int a,b;
    cout<<"input the value of a and b to check set bits"<<endl;
    cin>>a>>b;
    cout<<"number of set bits in a is "<<count_set_bits(a)<<endl;
    cout<<"number of set bits in b is "<<count_set_bits(b)<<endl;

}

void fibbonacci(){
    int n;
    cout<<"input the term of which you want fibbonacci of"<<endl;
    cin>>n;
    int a = 0,b=1;
    for(int i=1;i<n;i++){
        int temp = b;
        b = a+b;
        a = b;
    }
    cout<<"the nth term of the series is "<<a<<endl;
}

int main(){
    ap();
    set_bits();
    fibbonacci();
}