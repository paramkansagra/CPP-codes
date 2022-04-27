#include<iostream>
 
using namespace std;
 
class Node{
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};

void insertAtTail(Node* &tail,int n){
    Node* temp = new Node(n); // making new temp node
    tail->next = temp; // next of tail set as temp
    temp->prev = tail; // prev of temp set as tail
    tail = temp; // new tail is temp
}

int getLength(Node* &head){
    Node* temp = head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }

    return length;
}

int main(){

    Node* Node1 = new Node(10);
    Node* head = Node1;
    Node* tail = Node1;

    insertAtTail(tail,11);
    insertAtTail(tail,12);
    
    cout<<getLength(head)<<endl;

    return 0;
}