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

void removeDuplicates(Node* head){
    if(head == NULL){
        return ;
    }

    while(head != NULL){
        if(head->next != NULL){
            if(head->data != head->next->data){
                head = head->next;
            }
            else{
                Node* temp = head->next;
                head->next = head->next->next;

                temp->next = NULL;
                delete temp;
            }
        }
        else{
            break;
        }
    }
}

// inserting at the top // time Complexity O(1)
void insertAtHead(Node* &head,int d){ // we are not making a copy we are changing the next list
    // create new node
    Node* temp = new Node(d); // making a temp node to point at
    temp->next = head; // saying temp's next address is equal to head
    head = temp; // now the new head is temp
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

    insertAtHead(head,11);
    insertAtHead(head,11);
    insertAtHead(head,12);
    insertAtHead(head,13);
    insertAtHead(head,13);
    print(head);

    removeDuplicates(head);
    print(head);

    return 0;
}