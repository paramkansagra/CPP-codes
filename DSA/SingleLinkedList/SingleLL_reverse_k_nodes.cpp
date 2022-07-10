#include<iostream>
 
using namespace std;
 
// class creating the diffrent nodes
class Node{
    public:
        int data;
        Node* next;

        // constructor
        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        // destructor
        ~Node(){
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
        }
};

// inserting at the top // time Complexity O(1)
void insertAtHead(Node* &head,int d){ // we are not making a copy we are changing the next list
    // create new node
    Node* temp = new Node(d); // making a temp node to point at
    temp->next = head; // saying temp's next address is equal to head
    head = temp; // now the new head is temp
}

// inserting at the end of the LL
void insertAtTail(Node* &tail,int d){
    // creating a new node
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

Node* reverseKnodes(Node* head,int k){
    
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    int count = 0;

    // step 1 reverse the first k nodes
    while(curr != NULL && count<k){
        next = curr->next;
        curr->next = prev; 
        prev = curr;
        curr = next;
        count++;
    }

    // step 2 age ka recursion sambhal lega
    if(next != NULL){
        head->next = reverseKnodes(next,k);
    }

    // returning the prev because of the theory dek lena
    return prev;
}

// inserting the node at a position // O(n)
void insertAtPosition(Node* &head,Node* &tail,int pos,int d){

    if(pos == 1){
        insertAtHead(head,d);
        return ;
    }

    Node* temp = head; // creating new node for d
    Node* insert = new Node(d);

    int count = 1;
    while(count<pos-1){
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){ // inserting at last pos
        tail = insert;
    }

    insert->next = temp->next;
    temp->next = insert;
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
    Node* tail = node1;
    
    insertAtTail(tail,12);
    insertAtTail(tail,15);
    insertAtTail(tail,22);

    print(head);

    cout<<"Head "<<head->data<<" Tail "<<tail->data<<endl;

    return 0;
}
