#include <bits/stdc++.h>
 
using namespace std;
 
class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(){
            this->data = -1;
            this->left = NULL;
            this->right = NULL;
        }

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node* root,int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    Node* temp = new Node(data);

    // root ke right part me the data is greater than the root
    // root ke left part me the data is great than that of the root

    if(data > root->data){
        // right part me jao and insert the data recursively
        root->right = insertIntoBST(root->right,data);
    }
    else{ 
        // left part me jao and insert the data recursively
        root->left = insertIntoBST(root->left,data);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

// we are finding the inOrderTraversal of a bst
void inOrder(Node* root,vector<int>& inOrderTraversal){
    if(root == NULL){ // the base case is if the root is null then end the function and return 
        return ;
    }

    inOrder(root->left,inOrderTraversal); // so for a inOrderBST we have to first go in the left node
    inOrderTraversal.push_back(root->data); // then add the root node into the vector
    inOrder(root->right,inOrderTraversal); // then go in the right side of the node
}

Node* flattenTree(Node* root){
    vector<int> inOrderTraversal; // so first we have to find the inOrderTraversal of the tree
    inOrder(root,inOrderTraversal);

    int n = inOrderTraversal.size(); // we are setting n as the size of the inOrderTraversal

    // the process we are going to follow here is
    // as we have got the inOrderTraversal of the tree 
    // now we can just make a linkedList kind of thing using the tree nodes
    // we will keep all the left nodes are null and add the next data in the right nodes
    // for the last node we are keeping both the left and the right side node as NULL

    Node* newRoot = new Node(inOrderTraversal[0]); // we first made the newRoot node
    Node* curr = newRoot; // making a curr node for traversal and adding new nodes
    
    for(int i=1;i<n;i++){ // go from the 0th index to the nth index
        Node* temp = new Node(inOrderTraversal[i]); // find the node and make a new one
        
        curr->left = NULL; // make the curr's left as null
        curr->right = temp; // and the right side as the temp node
        curr = temp; // now make curr as temp
    }

    curr->left = NULL; // as it is the last node keep both the left side and the right side as null
    curr->right = NULL;

    return newRoot; // return the main top node 
}

void print(Node* root){ // printing the bst
    while(root != NULL){ // keep printing till the root is not NULL 
        cout<<root->data<<" "; // print the data
        root = root->right; // and go on the right side as all the left side nodes are null
    }
}

int main(){

    Node* root = NULL;
    cout<<"Enter data to create a BST"<<endl;

    takeInput(root);

    root = flattenTree(root);
    print(root);

    return 0;
}