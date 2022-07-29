#include <iostream>
#include <queue>

using namespace std;

class stack{
    private:
        deque<int> dq;
    
    public:
        void push(int data){
            dq.push_front(data);
        }

        int pop(){
            int data = dq.front();
            dq.pop_front();
            return data;
        }

        int top(){
            return dq.front();
        }

        int size(){
            return dq.size();
        }
};

int main(){

    return 0;
}