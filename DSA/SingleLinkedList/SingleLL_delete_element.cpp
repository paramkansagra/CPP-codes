#include<iostream>
 
using namespace std;
 
class Node{
    public:
        int value;
        Node* next;

        Node(int value=0){
            this->value = value;
            this->next = NULL;
        }
        
        ~Node(){
            if(this->next == NULL){
                delete next;
                this->next = NULL;
            }
        }
};

void insertAtHead(Node* &head,int d){
    // make a temp node for d
    Node* temp = new Node(d);
    temp->next = head; // the next element of temp is head
    head = temp; // new head is temp
}

void insertAtTail(Node* &tail,int d){
    // make a temp node for d
    Node* temp = new Node(d);
    tail->next = temp; // tail ka next element is temp
    tail = temp; // new tail
}

void deleteElement(Node* &head,Node* &tail,int value){
    if(value == head->value){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        bool found = false;
        while(curr->value != value && curr->next != NULL){
            prev = curr;
            curr = curr->next;
            if(curr->value == value){
                found = true;
            }
        }
        if(curr->next == NULL && found == true){
            tail = prev;
            tail->next = NULL;
            curr->next = NULL;
            delete curr;
        }
        else if(found){
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
    }
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->value<<" ";
        temp = temp->next;
    }cout<<endl;
}

int main(){

    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail,11);
    insertAtTail(tail,12);
    insertAtTail(tail,13);
    insertAtTail(tail,14);

    print(head);

    deleteElement(head,tail,14);

    print(head);

    return 0;
}