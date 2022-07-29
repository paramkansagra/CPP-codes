#include <iostream>
#include <queue>

using namespace std;
 
int main(){

    deque <int> dq;

    dq.push_front(12);
    dq.push_back(14);
    
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;

    dq.pop_front();

    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;

    dq.pop_back();

    if(dq.empty()){
        cout<<"the dequeue is empty"<<endl;
    }
    else{
        cout<<"the dequeue is not empty"<<endl;
    }

    return 0;
}