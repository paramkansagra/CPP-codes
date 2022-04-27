#include<iostream>
 
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        // constr
        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        // dest
        ~Node(){
            int value = this->data;
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
            cout<<"The memory is freed with value "<<value<<endl;
        }
};

void insertNode(Node* &tail,int eleCompare, int d){
    if(tail == NULL){
        Node* insert = new Node(d);
        insert->next = insert;
        tail = insert;
    }
    else{
        Node* curr = tail;
        Node* insert = new Node(d);
        while(curr->data != eleCompare){
            curr = curr->next;
        }
        insert->next = curr->next;
        curr->next = insert;
    }
}

void deleteNode(Node* &tail,int d){
    if(tail == NULL){
        cout<<"LL is empty check"<<endl;
        return ;
    }
    else{
        // not empty // value exists in the LL
        Node* prev = tail;
        Node* curr = tail->next;
        while(curr->data != d){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // 1 node ll
        if(curr == prev){
            tail = NULL;
        }

        else if(tail == curr){ // handeling the edge case
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void print(Node* tail){
    Node* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);
    cout<<endl;
}

int main(){

    Node* tail = NULL;
    
    insertNode(tail,0,10);
    print(tail);

    insertNode(tail,10,11);
    print(tail);

    insertNode(tail,11,12);
    print(tail);

    deleteNode(tail,10);
    print(tail);

    return 0;
}