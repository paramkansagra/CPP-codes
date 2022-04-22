#include <bits/stdc++.h>

using namespace std;

void reverseString(char ch[],int n){
    int start = 0;
    int end = n-1;
    while(start<end){
        swap(ch[start++],ch[end--]);
    }
}

int getLength(char ch[]){
    int count = 0;
    for(int i=0;ch[i] != '\0';i++){
        count++;
    }
    return count;
}

int main(){
    char ch[20];
    cin>>ch;

    int n = getLength(ch);
    reverseString(ch,n);
    cout<<ch<<endl;

    int a = 'a';
    int b = 'z';
    int c = 'A';
    int d = 'Z';
    int e = '0';
    int f = '9';
    cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;

    return 0;
}