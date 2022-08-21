#include <iostream>
#include <queue>
#include <map>

using namespace std;

// making class node for the tree
class Node{
    public:
        int data; // it will have 3 arguments data left node and right node
        Node* left;
        Node* right;

        Node(int data){ // making a constructor where incoming data is being set to object
            this->data = data;
            this->left = NULL; // putting left & right as NULL initially
            this->right = NULL;
        }
};

// post order traversal is LRN => left right node
void printPostOrderTraversal(Node* root){
    if(root == NULL){
        return ;
    }
    // making a post order traversal function
    printPostOrderTraversal(root->left); // going in the left of the node
    printPostOrderTraversal(root->right); // going in the right of the node
    cout<<root->data<<" "; // printing the data of the node
}

// we are creating a mapping from inOrderTraversal to the index on which they are stored in order to
// reduce the time on finding the position from which we have to start and end for inOrderTraversal
void buildMapping(int inOrderTraversal[],int n,map<int,int>& nodeToIndex){
    for(int i=0;i<n;i++){ // starting from 0 and till n-1
        nodeToIndex[inOrderTraversal[i]] = i; // make a mapping of the element to the index where they are stored
    }
}

// so this solve function is the main function we are dealing with
// so here we are taking all the array preOrderIndex inOrderStart inOrderEnd n and mapping in the input
// so the use of the preOrderIndex is that it stores till what we have reached in the preOrderTraversal
// the inOrderStart and inOrderEnd deals with from where we have to start and end the inOrderTraversal for finding the left right and root node
// so we take the first node we know is the root and then find the element in the inOrderTraversal
// find the index and then go for the left and right of the inOrderTraversal as normal and repeat the process
Node* solve(int inOrderTraversal[],int preOrderTraversal[],int &preOrderIndex,int inOrderStart,int inOrderEnd,int n,map<int,int>& nodeToIndex){
    if(preOrderIndex>=n || inOrderStart>inOrderEnd){ // if the preOrderIndex is more than n or if the inOrderStart becomes more than inOrrder end
        return NULL; // then return NULL cause no node will present at that position
    }

    int element = preOrderTraversal[preOrderIndex++]; // now we have to find the element for the node
    Node* root = new Node(element); // make the root node for that element

    int position = nodeToIndex[element]; // now find the position of the same in the inOrderTraversal

    root->left = solve(inOrderTraversal,preOrderTraversal,preOrderIndex,inOrderStart,position-1,n,nodeToIndex); // we will be going in the left of the inOrderTraversal to find the left node of the element
    root->right = solve(inOrderTraversal,preOrderTraversal,preOrderIndex,position+1,inOrderEnd,n,nodeToIndex); // we will be going in the right of the inOrderTraversal to find the right node of the element

    return root; // return root when these things are done
}

Node* buildTree(int inOrderTraversal[],int preOrderTraversal[],int n){
    map<int,int> nodeToIndex; // making a mapping in order to reduce the time complexity to find a element
    buildMapping(inOrderTraversal,n,nodeToIndex);

    int preOrderIndex = 0;

    Node* ans = solve(inOrderTraversal,preOrderTraversal,preOrderIndex,0,n-1,n,nodeToIndex); // making a answer node and calling the solve function

    return ans; // return the answerNode
}

int main(){

    int n;
    cin>>n;

    int preOrderTraversal[n],inOrderTraversal[n];
    for(int i=0;i<n;i++){
        cin>>preOrderTraversal[i];
    }
    for(int i=0;i<n;i++){
        cin>>inOrderTraversal[i];
    }

    Node* root = buildTree(inOrderTraversal,preOrderTraversal,n);
    printPostOrderTraversal(root);
    cout<<endl;

    return 0;
}