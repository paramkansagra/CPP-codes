#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
int arr[N] , tree[4 * N];

void build(int node , int start , int end){
    if(start == end){
        tree[node] = arr[start];
        return ;
    }

    int mid = start + (end - start) / 2;

    build(2 * node , start , mid);
    build(2 * node + 1 , mid + 1 , end);

    tree[node] = max(tree[2 * node] , tree[2 * node + 1]);
}

int query(int node , int start , int end , int query_start , int query_end){
    if(start > query_end || end < query_start) return INT_MIN;

    if(query_start <= start && query_end >= end) return tree[node];

    int mid = start + (end - start) / 2;
    int left = query(2 * node , start , mid , query_start , query_end);
    int right = query(2 * node , mid + 1 , end , query_start , query_end);

    return max(left , right);
}

void update(int node , int start , int end , int index , int value){
    if(start > index || end < index) return;

    if(index <= start && index >= end){
        tree[node] = max(tree[node] , value);
        return;
    }

    int mid = start + (end - start / 2);
    update(2 * node , start , mid , index , value);
    update(2 * node + 1 , mid + 1 , end , index , value);

    tree[node] = max(tree[2 * node] , tree[2 * node + 1]);
}

int main(){

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    build(1 , 0 , n - 1);

    int ans = query( 1 , 0 , n - 1 , 1 , 3);
    cout<<ans;

    return 0;
}