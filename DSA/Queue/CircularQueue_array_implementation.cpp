#include <iostream>
 
using namespace std;
 
class queue{
    private:
        int* arr;
        int qfront;
        int qrear;
        int size;

    public:
        queue(int n){
            size = n;
            arr = new int[size];
            qfront = -1;
            qrear = -1;
        }

        bool push(int data){
            if((qfront == 0 && qrear == size-1) || (qrear == (qfront-1)%(size-1))){
                cout<<"queue is full"<<endl;
                return false;
            }
            if(qfront == -1){
                qfront = qrear = 0;
            }
            else if(qrear == size-1 && qfront != 0){
                qrear = 0;
            }
            else{
                qrear++;
            }
            
            arr[qrear] = data;
            return true;
        }

        int pop(){
            if(qfront == -1){
                cout<<"the queue is empty"<<endl;
                return -1;
            }

            int ans = arr[qfront];
            if(qfront == qrear){
                qfront = qrear = -1;
            }
            if(qfront = size-1){
                qfront = 0;
            }
            else{
                qfront++;
            }

            return ans;
        }

        int front(){
            if(qfront == -1) return -1;
            return arr[qfront];
        }

        int back(){
            if(qrear == -1) return -1;
            return arr[qrear];
        }

        bool empty(){
            if(qfront == -1) return true;
            return false;
        }

        int qsize(){
            if(qfront == -1) return 0;
            if(qfront<qrear) return qrear-qfront;
            else return size-qfront-qrear+1;
        }
};

int main(){

    queue q(20);

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