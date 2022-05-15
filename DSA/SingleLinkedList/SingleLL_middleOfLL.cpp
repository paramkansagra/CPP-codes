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

int getLength(Node* head){
    int length = 0;
    while(head != NULL){
        length++;
        head = head->next;
    }

    return length;
}

Node* middleNode(Node* head){
    int length = getLength(head);
    length = length/2;
    int count = 0;

    while(count<length){
        count++;
        head = head->next;
    }
    return head;
}

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
