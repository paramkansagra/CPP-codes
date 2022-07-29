#include <iostream>
#include <queue>
#include <stack>

using namespace std;
 
queue<int> interleaveFirstHalfWithSecond(queue<int> q){
    int n = q.size();
    stack<int> temp;

    for(int i=0;i<n/2;i++){
        temp.push(q.front());
        q.pop();
    }

    stack<int> st;
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();

        q.push(q.front());
        q.pop();
    }

    return q;
}

queue<int> interleaveFirstHalfWithSecond2(queue<int> q){
    queue<int> temp;
    int n = q.size();

    for(int i=0;i<n/2;i++){
        temp.push(q.front());
        q.pop();
    }

    while(!temp.empty()){
        q.push(temp.front());
        q.push(q.front());
        q.pop();
        temp.pop();
    }

    return q; 
}

void print(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main(){

    int n;
    cin>>n;

    queue<int> q;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        q.push(temp);
    }   

    queue<int> ans = interleaveFirstHalfWithSecond(q);
    print(ans);

    return 0;
}