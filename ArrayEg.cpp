#include <bits/stdc++.h>

using namespace std;

int getMin(int arr[],int n){
    int minn=INT_MAX;

    for(int i=0;i<n;i++){
        minn = min(arr[i],minn);
    }
    
    return minn;
}

int getMax(int arr[],int n){
    int maxx=INT_MIN;

    for(int i=0;i<n;i++){
        maxx = max(maxx,arr[i]);
    }

    return maxx;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<getMax(arr,n)<<endl;
    cout<<getMin(arr,n)<<endl;

    return 0;
}