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

// here we will be calculating the height of the tree recursively
// now we have to solve 1 base case and other will be solved by recursion
// base case is if root == NULL return 0
// else go in left of a node and right of a node and get max of left and right + 1
int getHeightOfTree(Node* root){
    if(root == NULL){
        return 0;
    }

    int left = getHeightOfTree(root->left);
    int right = getHeightOfTree(root->right);

    return max(left,right)+1;
}

int main(){

    Node* root = NULL;

    // creating a tree
    root = buildTree(root);

    int ans = getHeightOfTree(root);

    cout<<ans<<endl;

    return 0;
}