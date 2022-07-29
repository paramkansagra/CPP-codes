#include <iostream>
#include <queue>

using namespace std;

int main(){

    // creating a queue
    queue<int> q;

    // enqueue => pushing the elements in the queue
    // dequeue => popping the elements out of the queue

    // pushing elements in the queue
    q.push(11);
    cout<<"the front of queue is "<<q.front()<<endl; // printing the front and back elements
    cout<<"the back of queue is "<<q.back()<<endl;

    q.push(12);
    cout<<"the front of queue is "<<q.front()<<endl;
    cout<<"the back of queue is "<<q.back()<<endl; // the front element is the same but the back element keeps changing

    q.push(13);
    cout<<"the front of queue is "<<q.front()<<endl;
    cout<<"the back of queue is "<<q.back()<<endl;

    q.push(14);
    cout<<"the front of queue is "<<q.front()<<endl;
    cout<<"the back of queue is "<<q.back()<<endl;

    cout<<"the size of the queue is "<<q.size()<<endl; // printing the size of the queue

    q.pop(); // poping the element 
    cout<<"the front of the queue is "<<q.front()<<endl; // the front element changes cause we popped a ele
    cout<<"the back of the queue is "<<q.back()<<endl;

    cout<<"the size of the queue is "<<q.size()<<endl; // printing the size of the queue to check if changed

    if(q.empty()){
        cout<<"the queue is empty"<<endl;
    }
    else{
        cout<<"the queue is not empty"<<endl;
    }

    return 0;
}