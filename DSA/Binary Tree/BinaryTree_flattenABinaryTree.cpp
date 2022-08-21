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

Node* findPredessor(Node* curr){
    Node* ans = curr->right;
    while(ans->right != NULL){
        ans = ans->right;
    }
    return ans;
}

void flattenTree(Node* root){
    // the work is we have to flatten the binary tree
    // soo we will use morris traversal for the same
    // we use to point the prev to curr this time we will point it to curr->right
    // and go in the left part and do the same

    Node* curr = root;
    while(curr != NULL){
        if(curr->left != NULL){
            Node* prev = curr->left;
            while(prev->right != NULL){
                prev = prev->right; // going in the right most node
            }

            // point its right to the curr's right
            prev->right = curr->right; // point the prev right node to curr's right node
            curr->right = curr->left; // making the right node point towards the left node
            // in short making the right node dissaper cause it is handeled by the prev node

            curr->left = NULL; // making the curr->left as NULL as there should be no links present there
        }
        curr = curr->right; // going in the right side to process more data
    }
}

void printTree(Node* root){
    if(root == NULL){
        cout<<endl;
        return ;
    }
    printTree(root->left);
    cout<<root->data<<" ";
    printTree(root->right);
}

int main(){

    Node* root = NULL;
    root = buildTree(root);

    flattenTree(root);
    printTree(root);
 
    return 0;
}