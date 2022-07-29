#include <iostream>

using namespace std;

class Node{
    public:
        Node* next;
        int data;
    
        Node(){
            next = NULL;
            data = 0;
        }

        Node(int data){
            this->data = data;
            next = NULL;
        }

        ~Node(){
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
        }
};

class deque{
    private:
        Node* head;
        Node* tail;
        int size;

    public:
        deque(){
            head = NULL;
            tail = NULL;
            size = 0;
        }

        void push_front(int data){
            Node* temp = new Node(data);
            if(isEmpty()){
                head = temp;
                tail = temp;
            }
            else{
                temp->next = head;
                head = temp;
            }
            size++;
        }

        void push_back(int data){
            Node* temp = new Node(data);
            if(isEmpty()){
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = temp;
            }
            size++;
        }

        int pop_front(){
            if(isEmpty()){
                return -1;
            }
            else{
                int data = head->data;
                Node* temp = head;

                if(head->next != NULL){
                    head = head->next;

                    temp->next = NULL;
                    delete temp;
                }
                else{
                    head = head->next;
                    tail = NULL;

                    tail->next = NULL;
                    delete temp;
                }
                size--;
                return data;
            }
        }

        int pop_back(){
            if(isEmpty()){
                return -1;
            }
            Node* curr = head;
            Node* prev = NULL;

            while(curr->next != NULL){
                prev = curr;
                curr = curr->next;
            }

            tail = prev;
            tail->next = NULL;

            int data = curr->data;

            delete curr;

            return data;
        }

        int front(){
            if(isEmpty()){
                return -1;
            }
            return head->data;
        }

        int back(){
            if(isEmpty()){
                return -1;
            }
            return tail->data;
        }

        bool isEmpty(){
            if(head == NULL || tail == NULL){
                return true;
            }
            return false;
        }
};

int main(){

    deque dq;

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