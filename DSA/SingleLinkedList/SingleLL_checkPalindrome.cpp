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

Node* findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

bool checkPalindrome(Node* head){
    if(head == NULL || head->next == NULL){
        return true;
    }

    Node* middle = findMiddle(head);
    Node* temp = middle->next;
    middle->next = reverse(temp);

    Node* head1 = head;
    Node* head2 = middle->next;

    while(head2 != NULL){
        if(head1->val != head2->val){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    temp = middle->next;
    middle->next = reverse(temp);

    return true;
}

int main(){

    Node* head = new Node(10);
    Node* tail = head;

    print(head);

    return 0;
}