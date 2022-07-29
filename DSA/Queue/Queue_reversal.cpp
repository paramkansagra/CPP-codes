#include <iostream>
#include <queue>
#include <stack>

using namespace std;
 
void reverseQueueUsingStack(queue<int>& q){
    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
}

void reverseQueue(queue<int>& q){
    if(q.empty()) return ;

    int data = q.front();

    q.pop();

    reverseQueue(q);
    q.push(data);
}

void Print(queue<int> q){
    while(q.empty() == false){
        cout<<q.front()<<" ";
        q.pop();
    }
}

int main(){

    queue<int> Queue;
    Queue.push(10);
    Queue.push(20);
    Queue.push(30);
    Queue.push(40);
    Queue.push(50);
    Queue.push(60);
    Queue.push(70);
    Queue.push(80);
    Queue.push(90);
    Queue.push(100);
 
    reverseQueue(Queue);
    Print(Queue);

    return 0;
}