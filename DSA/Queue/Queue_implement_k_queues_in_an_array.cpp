#include <iostream>

using namespace std;

class kqueue{
    private:
        int n,k;
        int* front;
        int* rear;
        int* arr;
        int* next;
        int freeSpot;
    
    public:
        kqueue(int n,int k){
            this->n = n;
            this->k = k;

            front = new int[k];
            rear = new int[k];
            arr = new int[n];
            next = new int[n];

            freeSpot = 0;

            for(int i=0;i<k;i++){
                front[i] = -1;
                rear[i] = -1;
            }

            for(int i=0;i<n;i++){
                next[i] = i+1;
            }
            next[n-1] = -1;
        }

        void push(int data,int qn){
            // over flow
            if(freeSpot == -1){
                cout<<"No empty space avaliable"<<endl;
                return ;
            }

            // find first free index;
            int index = freeSpot;
            freeSpot = next[index];

            if(front[qn-1] == -1){
                front[qn-1] = index;
            }
            else{
                // link new element to prev element
                next[rear[qn-1]] = index;
            }

            // update next
            next[index] = -1;

            // update rear
            rear[qn-1] = index;

            // push element
            arr[index] = data;
        }

        int pop(int qn){
            // check underflow condition
            if(front[qn-1] == -1){
                cout<<"queue underflow"<<endl;
                return -1;
            }

            // find index to pop
            int index = front[qn-1];

            // front ko aage badhao
            front[qn-1] = next[index];

            // manage free slot
            next[index] = freeSpot;
            freeSpot = index;

            return arr[index];
        }
};

int main(){

    kqueue q(10,3);
    q.push(10,1);
    q.push(15,1);
    q.push(20,2);
    q.push(25,1);

    cout<<q.pop(1)<<endl;
    cout<<q.pop(2)<<endl;
    cout<<q.pop(1)<<endl;
    cout<<q.pop(1)<<endl;
    cout<<q.pop(1)<<endl;

    return 0;
}