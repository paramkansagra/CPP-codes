#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    
        Node(){
            data = -1;
            next = NULL;
            prev = NULL;
        }

        Node(int data){
            this->data = data;
            next = NULL;
            prev = NULL;
        }

        ~Node(){
            if(next != NULL){
                delete next;
                next = NULL;
            }
        }
};

void insertAtHead(int data,Node* &head,Node* & tail){
    Node* temp = new Node(data);
    if(head == NULL && tail == NULL){
        head = temp;
        tail = temp;
    }
    else{
        temp->next = head;
        head = temp;
    }
}

void insertAtTail(int data,Node* &head,Node* &tail){
    Node* temp = new Node(data);
    if(head == NULL && tail == NULL){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
}

void printLL(Node* head,Node* tail){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

void swap(int* a,int* b){
    int* temp = a;
    a = b;
    b = temp;
}

Node* partition(Node* l,Node* h){
    int x = h->data;
    Node* i = h->prev;
    for(Node* j = l;j != h;j = j->next){
        if(j->data <= x){
            if(i != NULL) i = i->next;
            else i = l;

            swap(&(j->data),&(i->data));
        }
    }
    swap(&(i->data),&(h->data));
    return(i);
}

void quickSort(Node* head,Node* tail){
    
    if(head != NULL && tail != NULL && head->next != tail){
        Node* partNode = partition(head,tail);
        quickSort(head,partNode->prev);
        quickSort(partNode->next,tail);
        printLL(head,tail);
    }

}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    while(true){
        int temp;
        cout<<"input the data // if no data input -1"<<endl;
        cin>>temp;

        if(temp != -1){
            insertAtTail(temp,head,tail);
        }
        else{
            break;
        }
    }

    quickSort(head,tail);

    return 0;
}