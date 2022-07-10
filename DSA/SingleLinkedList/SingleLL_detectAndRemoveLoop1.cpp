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

    if(head == NULL){ // checking if the list is empty or not
        return false;
    }

    Node* curr = head; // making a curr so we can traverse the linked list
    map<Node*,bool> visited; // making a map to check if it was visited or not

    while(curr != NULL){ // traversing the ll
        if(visited.find(curr->next) == visited.end()){ // checking if the next element is present in the map or not
            visited.insert({curr,true}); // if the element is not present then push the element in the map
        }
        else{
            curr->next = NULL; // if the next element is present in the map then we will change the next element to null
            return true; // and return true as loop is present
        }
        curr = curr->next; // going forward in the ll
    }

    return false; // if nothing is returned then we will return false as no loop is present
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
