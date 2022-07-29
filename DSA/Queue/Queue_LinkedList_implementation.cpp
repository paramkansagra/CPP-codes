#include <iostream>
 
using namespace std;

template <class T>
class Node{
    public:
        Node* next;
        T data;

        Node(){
            data = 0;
            next = NULL;
        }

        Node(T data){
            this->data = data;
            next = NULL;
        }


        ~Node(){
            if(this->next != NULL){
                this->next = NULL;
                delete next;
            }
        }
};

template <class T>
class queue{
    private:
        Node<T>* qfront;
        Node<T>* qback;
        int size;
    
    public:
        queue(){
            qfront = NULL;
            qback = NULL;
            size = 0;
        }

        bool empty(){
            if(qfront == NULL && qback == NULL){
                return true;
            }
            return false;
        }

        void push(T data){
            Node<T>* temp = new Node<T>(data);
            if(qfront == NULL){
                qfront = temp;
            }
            if(qback == NULL){
                qback = temp;
            }
            else{
                qback->next = temp;
                qback = temp;
            }

            size++;
        }

        int pop(){
            T ans;

            if(qfront == qback && qfront != NULL){
                ans = qfront->data;
                Node<T>* temp = qfront;
                qfront = qfront->next;
                qback = NULL;

                temp->next = NULL;

                delete temp;
                size--;
            }
            else if(qfront != NULL){
                ans = qfront->data;
                Node<T>* temp = qfront;
                qfront = qfront->next;

                temp->next = NULL;

                delete temp;
                size--;
            }
            else{
                ans = -1;
            }

            return ans;
        }

        T front(){
            if(qfront != NULL) return qfront->data;
            return -1;
        }

        T back(){
            if(qback != NULL) return qback->data;
            return -1;
        }

        int getSize(){
            return size;
        }
};

int main(){

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

    cout<<"the size of the queue is "<<q.getSize()<<endl; // printing the size of the queue

    q.pop(); // poping the element 
    cout<<"the front of the queue is "<<q.front()<<endl; // the front element changes cause we popped a ele
    cout<<"the back of the queue is "<<q.back()<<endl;

    cout<<"the size of the queue is "<<q.getSize()<<endl; // printing the size of the queue to check if changed

    q.pop();
    q.pop();
    q.pop();

    if(q.empty()){
        cout<<"the queue is empty"<<endl;
    }
    else{
        cout<<"the queue is not empty"<<endl;
    }

    return 0;
}