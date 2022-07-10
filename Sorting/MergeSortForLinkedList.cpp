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

// inserting at the end of the LL
void insertAtTail(Node* &tail,int d){
    // creating a new node
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node* merge(Node* left,Node* right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }

    Node* head = new Node(-1);
    Node* curr = head;

    while(left != NULL && right != NULL){
        if(left->data<right->data){
            curr->next = left;
            curr = left;
            left = left->next;
        }
        else{
            curr->next = right;
            curr = right;
            right = right->next;
        }
    }

    if(left != NULL){
        curr->next = left;
    }
    if(right != NULL){
        curr->next = right;
    }

    return head->next;
}

Node* mergeSort(Node* head){
    Node* mid = findMid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    merge(left,right);
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;

    return 0;
}
