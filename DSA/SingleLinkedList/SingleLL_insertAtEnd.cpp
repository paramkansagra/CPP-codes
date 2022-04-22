#include<iostream>
 
using namespace std;
 
class Node{
    public:
        int data;
        Node* next;

        // constructor
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

// inserting at the end // time complexity O(n)
void insertAtEnd(Node* &head,int d){
    // creating a new node
    Node* temp = new Node(d);
    Node* tempHead = head; // creating a temp head

    while(tempHead->next != NULL){
        tempHead = tempHead->next; // traversing the ll till the next element not found null
    }
    tempHead->next = temp;
}

// traversing a ll // time complexity O(n)
void print(Node* &head){
    Node* temp = head; // makeing a temp head as head is passed by reference
    while(temp != NULL){ // till the temp->next is not NULL
        cout<<temp->data<<" "; // printing the data held by temp
        temp = temp->next; // then shifting the temp node address to the next address pointed by temp
    }cout<<endl;
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;

    print(head);
    
    insertAtEnd(head,12);
    print(head);

    insertAtEnd(head,15);
    print(head);

    return 0;
}
