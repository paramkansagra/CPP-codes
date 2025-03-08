#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 2;
int arr[N] , tree[4 * N];

static const auto _ = []{
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(0);

    return 0;
}();

void build(int node , int start , int end){
    if(start == end){
        tree[node] = arr[start];
        return ;
    }

    int mid = start + (end - start) / 2;
    
    build(2 * node , start , mid);
    build(2 * node + 1 , mid + 1 , end);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node , int start , int end , int query_start , int query_end){
    if(start > query_end || end < query_start) return 0;

    if(query_start <= start && query_end >= end) return tree[node];

    int mid = start + (end - start) / 2;
    int left = query(2 * node , start , mid , query_start , query_end);
    int right = query(2 * node + 1 , mid + 1 , end , query_start , query_end);

    return left + right;
}

void update(int node , int start , int end , int index , int val){
    if(start == end){
        tree[node] = val;
        arr[node] = val;

        return ;
    }

    int mid = start + (end - start) / 2;
    if(index <= mid) update(2 * node , start , mid , index , val);
    else update(2 * node + 1 , mid + 1 , end , index , val);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main(){
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    build(1 , 0 , n-1);

    while(1){
        int type;
        cin>>type;

        if(type == -1){
            break;
        }
        else if(type == 1){
            int l , r;
            cin>>l>>r;
            
            cout<<query(1 , 0 , n - 1 , l , r)<<endl;
        }
        else if(type == 2){
            int index , val;
            cin>>index>>val;
            
            update(1 , 0 , n - 1 , index , val);

            cout<<query(1 , 0 , n - 1 , 0 , n - 1)<<endl;
        }
    }

    return 0;
}