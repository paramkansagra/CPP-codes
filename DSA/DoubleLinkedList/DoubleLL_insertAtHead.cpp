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

void insertAtHead(Node* &head,int n){
    Node* temp = new Node(n); // makeing new temp node
    head->prev = temp; // prev of head set as temp
    temp->next = head; // next of temp set as head
    head = temp; // new head is temp
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
    insertAtHead(head,11);

    print(head);
    insertAtHead(head,12);
    
    print(head);
    return 0;
}