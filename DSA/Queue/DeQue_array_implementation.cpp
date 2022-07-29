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
            qfront = qrear = -1;
        }

        bool isEmpty(){
            if(qfront == -1 && qrear == -1) return true;
            return false;
        }

        bool isFull(){
            if((qfront == 0 && qrear == size-1) || (qfront != 0 && qrear == (qfront-1)%(size-1))) return true;
            return false;
        }

        bool push_front(int data){
            if(isFull()){
                cout<<"queue is full"<<endl;
                return false;
            }

            if(isEmpty()){
                qfront = 0;
                qrear = 0;
            }
            else if(qrear != size-1 && qfront == 0){
                qfront = size-1;
            }
            else{
                qfront--;
            }
            arr[qfront] = data;
            return true;
        }

        bool push_back(int data){
            if(isFull()){
                cout<<"queue is full"<<endl;
                return false;
            }

            if(isEmpty()){
                qfront = 0;
                qrear = 0;
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

        int pop_front(){
            if(isEmpty()){
                return -1;
            }

            int ans = arr[qfront];
            arr[qfront] = -1;

            if(qfront == qrear){
                qfront = -1;
                qrear = -1;
            }
            else if(qfront == size-1){
                qfront = 0;
            }
            else{
                qfront++;
            }

            return ans;
        }

        int pop_back(){
            if(isEmpty()){
                return -1;
            }

            int ans = arr[qrear];
            arr[qrear] = -1;

            if(qfront == qrear){
                qfront = qrear = -1;
            }
            else if(qrear == 0){
                qrear = size-1;
            }
            else{
                qrear--;
            }

            return ans;
        }

        int front(){
            if(isEmpty()) return -1;
            return arr[qfront];
        }

        int back(){
            if(isEmpty()) return -1;
            return arr[qrear];
        }
};

int main(){

    queue dq(10);

    dq.push_front(12);
    dq.push_back(14);
    
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;

    dq.pop_front();

    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;

    dq.pop_back();

    if(dq.isEmpty()){
        cout<<"the dequeue is empty"<<endl;
    }
    else{
        cout<<"the dequeue is not empty"<<endl;
    }

    return 0;
}