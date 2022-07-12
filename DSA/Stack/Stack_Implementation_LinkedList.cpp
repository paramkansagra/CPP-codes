#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;

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

class Stack{
    private:
        Node* head;
    
    public:
        Stack(){
            head = NULL;
        }

        void push(int data){
            Node* temp = new Node(data);
            temp->next = head;
            head = temp;
        }

        int pop(){
            if(head == NULL){
                return -1;
            }

            Node* temp = head->next;
            int data = head->data;
            head->next = NULL;

            delete head;
            
            head = temp;
            return data;
        }

        int peek(){
            if(head == NULL){
                return -1;
            }
            else{
                return head->data;
            }
        }
};

int main(){

    Stack st;
    st.push(10);
    cout<<st.peek()<<endl;
    st.push(11);

    cout<<st.peek()<<" ";
    st.pop();
    cout<<st.peek()<<" ";
    st.pop();
    cout<<st.peek()<<endl;

    return 0;
}