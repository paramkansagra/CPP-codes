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

// we will check if 2 trees are identical or not
bool isIdentical(Node* r1,Node* r2){
    if(r1 == NULL && r2 == NULL){ // if both the sides of the nodes are NULL
        return true; // then return true
    }

    if((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL)){ // if one of them is not NULL and other is NULL
        return false; // then return false
    }

    bool left = isIdentical(r1->left,r2->left); // go in the left side in both tree and check if identical
    bool right = isIdentical(r1->right,r2->right); // go in the right side in both tree and check if identical

    bool currValueCheck = r1->data == r2->data; // check if value of current node is same for both trees

    if(left && right && currValueCheck){ // if all the conditions are true for the both tree then return true
        return true;
    }
    return false; // else return false
}

int main(){

    Node* root = NULL;
    Node* root2 = NULL;

    // creating a tree
    root = buildTree(root);
    root2 = buildTree(root2);

    if(isIdentical(root,root2)){
        cout<<"both tree are identical"<<endl;
    }
    else{
        cout<<"both tree are not identical"<<endl;
    }

    return 0;
}