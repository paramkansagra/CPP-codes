#include<iostream>
 
using namespace std;
 
class Node{
    public:
        int value;
        Node* prev;
        Node* next;

        Node(int value){
            this->value = value;
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

void print(Node* &head){
    Node* temp = head; // making a temp node
    while(temp != NULL){ // till the node doesnt become NULL
        cout<<temp->value<<" "; // print its value
        temp = temp->next;
    }cout<<endl;
}

int main(){

    Node* Node1 = new Node(10);
    Node* head = Node1;
    Node* tail = Node1;

    print(head);
    insertAtTail(tail,11);

    print(head);
    insertAtTail(tail,12);
    
    print(head);
    return 0;
}