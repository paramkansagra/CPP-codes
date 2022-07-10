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

void insertAtTail(Node* &tail,int data){
    Node* newTail = new Node(data);
    tail->next = newTail;
    tail = newTail;
}

void print(Node* head){
    Node* curr = head;
    while(curr != NULL){
        cout<<curr->val<<" ";
        curr = curr->next;
    }cout<<endl;
}

void sort(Node* head){
    int count0=0,count1=0,count2=0;
    
    Node* curr = head;
    while(curr != NULL){
        if(curr->val == 0){
            count0++;
        }
        if(curr->val == 1){
            count1++;
        }
        if(curr->val == 2){
            count2++;
        }
    }

    curr = head;
    while(curr != NULL){
        if(count0 != 0){
            curr->val = 0;
            count0--;
        }
        else if(count1 != 0){
            curr->val = 1;
            count1--;
        }
        else if(count2 != 0){
            curr->val = 2;
            count2--;
        }
        curr = curr->next;
    }
}

int main(){

    Node* head = new Node(10);
    Node* tail = head;

    print(head);

    return 0;
}