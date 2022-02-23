#include <bits/stdc++.h>

using namespace std;

// queue is a FIFO type data structure
// first in first out

int main(){

    // we are intilizing the queue syntax is
    // queue<data_type> variable_name;
    queue<string> q;

    // we are adding the elements to the queue
    // just remeber first in first out
    q.push("param");
    q.push("kansagra");
    q.push("c++");

    // printing the first element in the queue
    cout<<"the first element in the queue is "<<q.front()<<endl;

    // we can remove the element from the queue as well
    q.pop();

    cout<<"the new first element in the queue is "<<q.front()<<endl;

    // we can also use find the size of the queue
    cout<<"the size of queue is "<<q.size()<<endl;

    // we can also empty the queue
    q.empty();


    return 0;
}