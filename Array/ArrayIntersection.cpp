#include <bits/stdc++.h>

using namespace std;

void arrayIntersection(int arr1[],int a,int arr2[],int b){
    vector<int> found;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(arr1[i] == arr2[j]){
                found.push_back(arr1[i]);
                break;
            }
        }
    }
    for(int i=0;i<found.size();i++){
        cout<<found[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int a,b;
    cin>>a>>b;
    
    int arr1[a],arr2[b];
    
    for(int i=0;i<a;i++){
        cin>>arr1[i];
    }
    for(int i=0;i<b;i++){
        cin>>arr2[i];
    }

    arrayIntersection(arr1,a,arr2,b);

    return 0;
}