#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;
int arr[N] , tree[4 * N];

void build(int node , int start , int end){
    if(start == end){
        tree[node] = arr[start];
        
        return ;
    }

    int mid = start + (end - start) / 2;
    build(2 * node , start , mid);
    build(2 * node + 1 , mid + 1 , end);

    tree[node] = min(tree[2 * node] , tree[2 * node + 1]);
}

int query(int node , int start , int end , int query_start , int query_end){
    if(start > query_end || end < query_start) return INT_MAX;

    if(start >= query_start && end <= query_end) return tree[node];

    int mid = start + (end - start) / 2;
    int left = query(2 * node , start , mid , query_start , query_end);
    int right = query(2 * node + 1 , mid + 1 , end , query_start , query_end);

    return min(left , right);
}

void update(int node , int start , int end , int index , int val){
    if(start == end){
        tree[node] = val;
        arr[node] = val;

        return ;
    }

    int mid = start + (end - start) / 2;
    if(index <= mid){
        update(2 * node , start , mid , index , val);
    }
    else{
        update(2 * node + 1 , mid + 1 , end , index , val);
    }

    tree[node] = min(tree[2 * node] , tree[2 * node + 1]);
}

int main(){

    int n ;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    build(1 , 0 , n - 1);

    while(1){
        int option;
        cin>>option;

        if(option == -1) break;
        if(option == 1){
            int query_start , query_end;
            cin>>query_start>>query_end;

            cout << query(1 , 0 , n - 1 , query_start , query_end) << endl;
        }
        if(option == 2){
            int index , val;
            cin >> index >> val;

            update(1 , 0 , n - 1 , index , val);

            cout << query(1 , 0 , n - 1 , 0 , n - 1) << endl;
        }
    }

    return 0;
}