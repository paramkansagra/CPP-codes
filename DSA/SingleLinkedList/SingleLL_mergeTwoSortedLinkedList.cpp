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

Node* mergeTwoSortedLinkedList(Node* head1,Node* head2){
    Node* head = new Node(-1);
    Node* curr = head;

    while(head1 != NULL && head2 != NULL){
        if(head1->val<head2->val){
            curr->next = head1;
            curr = head1;
            head1 = head1->next;
        }
        else{
            curr->next = head2;
            curr = head2;
            head2 = head2->next;
        }
    }

    if(head1 != NULL){
        curr->next = head1;
    }
    if(head2 != NULL){
        curr->next = head2;
    }

    return head->next;
}

int main(){

    Node* head = new Node(10);
    Node* tail = head;

    print(head);

    return 0;
}