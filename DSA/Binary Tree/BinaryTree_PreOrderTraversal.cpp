#include <iostream>
#include <queue>

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

// building in a recursive way
Node* buildTree(Node* root){

    cout<<"Enter data for the node "; // enter the data in the node
    int data;
    cin>>data;
    root = new Node(data); // create a node with the new data


    if(data == -1){ // if the data is -1 meaning it is NULL then return NULL
        return NULL;
    }
    cout<<"Enter data for inserting in the left of "<<data<<endl; // else go to left of the node
    root->left = buildTree(root->left); // ask the 

    cout<<"Enter data for inserting in the right of "<<data<<endl;
    root->right = buildTree(root->right);
}

// in PreOrderTraversal we have NLR format -> node left right format
// and we are going to print the same
void PreOrderTraversal(Node* root){
    
    cout<<root->data<<" ";
    
    if(root->left != NULL){
        PreOrderTraversal(root->left);
    }
    
    if(root->right != NULL){
        PreOrderTraversal(root->right);
    }
}

int main(){

    Node* root = NULL;

    // creating a tree
    root = buildTree(root);

    PreOrderTraversal(root);

    return 0;
}