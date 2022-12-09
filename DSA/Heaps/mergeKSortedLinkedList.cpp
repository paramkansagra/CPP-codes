#include <bits/stdc++.h>

using namespace std;

// making a class Node to store the linked list
class Node{
    public:
        int val; // integer to store the value
        Node* next; // next to store the next element

        // made a constructor to construct a new node with ease
        Node(int val){
            this->val = val;
            this->next = NULL;
        }
};

// making a function to input the n nodes for a linked list
Node* takeInput(int n){
    Node* head = NULL; // initially the head is null
    Node* curr = NULL; 

    for(int i=0;i<n;i++){
        int val; // take the input of the value
        cin>>val;

        Node* newNode = new Node(val); // make a new node

        if(curr == NULL){ // if the curr is null
            curr = newNode; // then make new Node as curr and head as curr
            head = curr;
        }
        else{
            curr->next = newNode; // else the newNode is the next and make curr the nextNode
            curr = curr->next;
        }
    }

    return head; // return the head
}

// making a new class to compare 2 nodes for the priority queue
class compare{
    public:
        bool operator()(Node* a,Node* b){
            return a->val > b->val;
        }
};

Node* mergeKSortedLL(vector<Node*> arr,int n){
    
    // make a new head and curr to store the linked list
    Node* head = NULL;
    Node* curr = NULL;

    // make a min heap
    priority_queue<Node* , vector<Node*> , compare> minHeap;

    // first push all the initial nodes in the minHeap
    for(int i=0;i<n;i++){
        minHeap.push(arr[i]);
    }

    // now till the heap is not 0 pull out the minimum element and store it in the LL
    while(!minHeap.empty()){
        
        Node* top = minHeap.top(); // find the minimum of the minHeap
        minHeap.pop(); // pop this element from the min heap

        if(curr == NULL){ // if the LL is empty
            Node* newNode = new Node(top->val); // make a new node of the same value as the top
            curr = newNode; // make curr as newNode
            head = curr; // and do the same for the head as the LL is empty
        }
        else{
            Node* newNode = new Node(top->val); // else make a new node of the same value as the top
            curr->next = newNode; // now curr->next is new Node
            curr = curr->next; // do curr = curr->next to store the next value incoming
        }

        if(top->next != NULL){ // if the top->next is not null meaning there are elements still left in the array
            minHeap.push(top->next); // then push that next element in minHeap
        }
    }

    // when the min heap is empty meaning there are no more elements to push return the head
    return head; // return the head
}

int main(){

    // input the number of nodes in the arrays
    int n;
    cin>>n;

    vector<Node*> arr(n); // made a vector to keep the arrays

    for(int i=0;i<n;i++){
        // input k the number of nodes in that linked list
        int k;
        cin>>k;

        Node* head = takeInput(k); // using the takeInput function we will be returned the head of the LL
        arr[i] = head; // append that head to the list of heads
    }

    Node* sortedHead = mergeKSortedLL(arr,n); // get the sortedLL head from the function
    
    Node* curr = sortedHead; // making a curr to print the sorted LL
    while(curr != NULL){ // while the curr is not NULL meaning there are still elements to be printed
        cout<<curr->val<<" "; // print the data
        curr = curr->next; // do curr = curr->next to get to the next element
    }

    return 0;
}