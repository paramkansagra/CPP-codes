#include <iostream>
 
using namespace std;
 
template <class T>
class queue{
    private:
        int qfront;
        int qrear;
        T* arr;
        int size;
    
    public:
        queue(){
            size = 10001;
            arr = new T[size];
            qfront = 0;
            qrear = 0;
        }

        bool empty(){
            if(qfront == qrear) return true;
            return false;
        }

        void push(int data){
            if(qrear == size){
                cout<<"the queue is full"<<endl;
            }
            else{
                arr[qrear++] = data;
            }
        }

        int pop(){
            if(qfront == qrear){
                return -1;
            }
            else{
                int ans = arr[qfront];
                arr[qfront] = -1;
                qfront++;

                if(qfront == qrear){
                    qfront = 0;
                    qrear = 0;
                }

                return ans;
            }
        }

        int front(){
            if(qfront == qrear) return -1;
            return arr[qfront];
        }

        int back(){
            if(qfront == qrear) return -1;
            return arr[qrear-1];
        }

        int qsize(){
            return (qrear-qfront);
        }
};

int main(){

    queue<int> q;

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

    cout<<"the size of the queue is "<<q.qsize()<<endl; // printing the size of the queue

    q.pop(); // poping the element 
    cout<<"the front of the queue is "<<q.front()<<endl; // the front element changes cause we popped a ele
    cout<<"the back of the queue is "<<q.back()<<endl;

    cout<<"the size of the queue is "<<q.qsize()<<endl; // printing the size of the queue to check if changed

    if(q.empty()){
        cout<<"the queue is empty"<<endl;
    }
    else{
        cout<<"the queue is not empty"<<endl;
    }

    return 0;
}