#include <iostream>
#include <queue>
#include <vector>

using namespace std;
 
void printFirstNegetiveInteger(int arr[],int n,int k){
    
    deque<int> q;
    vector<int> ans;

    for(int i=0;i<n;i++){
        if(arr[i]<0){
            q.push_back(i);
        }
    }

    if(q.size()>0){
        ans.push_back(arr[q.front()]);
    }
    else{
        ans.push_back(0);
    }

    for(int i=k;i<n;i++){
        // removal
        if(!q.empty() && i-q.front()>=k){
            q.pop_front();
        }

        // addition
        if(arr[i]<0){
            q.push_back(i);
        }

        // add in ans;
        if(q.size()>0){
            ans.push_back(arr[q.front()]);
        }
        else{
            ans.push_back(0);
        }
    }

    print(ans);
}

void print(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" "; 
    }cout<<endl;
}

int main(){

    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    
    printFirstNegetiveInteger(arr, n, k);
    
    return 0;
}