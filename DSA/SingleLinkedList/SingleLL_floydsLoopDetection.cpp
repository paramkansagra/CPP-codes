#include <iostream>
#include <map>
 
using namespace std;
 
class Node{
    public:
        int data;
        Node* next;

        // constructor
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

bool removeLoop(Node* &head){
    // simple algorithm
    // first make 2 nodes fast and slow and keep both of them on the start position
    // and traverse the linked list if any one of them finds a null in next
    // then no loop is there
    // else if they meet again then loop is present

    if(head == NULL){
        return false;
    }

    Node* slow = head;
    Node* fast = head;

    if(fast != NULL && slow != NULL){
        fast = fast->next;
        if(fast->next != NULL){
            fast = fast->next;
        }
        slow = slow->next;

        if(fast == slow){
            return true;
        }
    }

    return false;
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

    return 0;
}
