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

// using floyds loop detection algorithm
void removeLoop(Node* head){
    Node* slow = head; // first making a slow and a fast pointer
    Node* fast = head;

    while(slow != NULL && fast != NULL){ // traversing thru the linked list
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){ // when the slow and the fast pointers intersect we know the loop exists
            break; // now we break out of the while loop for removing the loop
        }
    }

    slow = head; // now we make slow as the head
    while(slow != fast){ // now go thru the while loop until the slow and fast pointers intersect agian
        slow = slow->next;
        fast = fast->next;
    }

    Node* temp = slow; // we are at the starting position of the loop
    while(temp->next != slow){ // we will go in the loop and work till the next node is not the intersecting node
        temp = temp->next;
    }

    temp->next = NULL; // when we find the node before the intersecting node we will make its next as null to flatten the LL
}

void devideIntoTwoLinkedList(Node* head,Node* &head1,Node* &head2){

    removeLoop(head); // removing the loop in the linkedList

    Node* slow = head; // making a slow and a fast pointer to find the middle of the array
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast->next != NULL){
            fast = fast->next; // going thru the array
        }
        else{
            fast->next = slow; // making a ciruclar LL for head1 and head2
            break;
        }
    }

    head2 = slow->next; // assigning head1 and head2 for the new 2 LL

    slow->next = head;
    head1 = head;
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
