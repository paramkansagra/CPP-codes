#include <iostream>

using namespace std;

class Node{
    public:
        int val;
        Node* next;
    
        Node(int data){
            this->val = data;
            this->next = NULL;
        }

        ~Node(){
            int x = val;
            cout<<"the data was "<<x<<endl;
            if(next != NULL){
                delete next;
                this->next = NULL;
            }
        }
};

void insertAtTail(Node* &tail,Node* curr){
    tail->next = curr;
    tail = curr;
}

void print(Node* head){
    Node* curr = head;
    while(curr != NULL){
        cout<<curr->val<<" ";
        curr = curr->next;
    }cout<<endl;
}

void sort(Node* &head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    while(curr != NULL){
        int val = curr->val;
        if(val == 0) insertAtTail(zeroTail,curr);
        if(val == 1) insertAtTail(oneTail,curr);
        if(val == 2) insertAtTail(twoTail,curr);
        curr = curr->next;
    }
    
    if(oneHead->next != NULL){
       zeroTail->next = oneHead->next;
    }
    else{
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    
    head = zeroHead->next;
    
    delete zeroHead;
    delete oneHead;
    delete twoHead;
}

int main(){

    Node* head = new Node(10);
    Node* tail = head;

    print(head);

    return 0;
}