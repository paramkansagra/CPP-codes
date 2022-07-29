#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverse(queue<int>& q,int n,int k){
    stack<int> st;
    for(int i=0;i<k;i++){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    for(int i=0;i<n-k;i++){
        int data = q.front();
        q.pop();
        q.push(data);
    }
}

void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main(){

    int n,k;
    cin>>n>>k;

    queue<int> q;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        q.push(temp);
    }

    reverse(q,n,k);
    print(q);

    return 0;
}