#include <bits/stdc++.h>

using namespace std;

int findSquareRoot(int n){
    int start = 0;
    int end = n;
    int mid = start + (end-start)/2;
    while(start<=end){
        if(mid*mid == n){
            return mid;
        }
        if(mid*mid<n && (mid+1)*(mid+1)>n){
            return mid;
        }
        else if(mid*mid>n){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        mid = start + (mid-start)/2;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;

    cout<<findSquareRoot(n)<<endl;
}