#include <iostream>
#include <stack>
 
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

Node* find(Node* root,int element){
    if(root == NULL){
        return NULL;
    }

    if(root->data == element){
        return root;
    }

    Node* left = find(root->left,element);
    Node* right = find(root->right,element);

    if(left == NULL && right == NULL){
        return NULL;
    }
    else if(left != NULL && right == NULL){
        return left;
    }
    else{
        return right;
    }
}

int minVal(Node* root){
    if(root == NULL){
        return NULL;
    }

    while(root->left != NULL){
        root = root->left;
    }
    
    return root->data;
}

Node* deleteNodeFromBST(Node* root,int element){
    // if the root is null then we cant do anything
    if(root == NULL){
        return NULL; // so return NULL
    }

    // now we if the root's data == element
    // write the deletion logic
    if(root->data == element){
        
        // 0 child of the root
        if(root->left == NULL && root->right == NULL){ // condition for a leaf node
            delete root;
            return NULL;
        }

        // 1 child of the root
        // 2 cases are there if there is a left node present or a right node present

        // left child
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if(root->right != NULL && root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child of the root
        if(root->left != NULL && root->right != NULL){
            // there are 2 options
            // to find the preOrderSuccessor and replace the value with it and delete that node
            // or to find the preOrderPredessor and replace the value with it and delete that node
            int min = minVal(root->right); // doing preOrderSuccessor // ek right then left
            root->data = min; // changing the data of the root
            root->right = deleteNodeFromBST(root->right,min); // deleting the right node of the bst
            return root; // returning the root now
        }
    }
    // if the root's data is smaller than the element then go in the right side
    else if(root->data < element){
        root->right = deleteNodeFromBST(root->right,element); // replace the right of the root with the incoming node
        return root; // return the node
    }
    // if the root's data is greater than the element then go in the left side
    else{
        root->left = deleteNodeFromBST(root->left,element); // replace the left of the root with the incoming node 
        return root; // return the node
    }
}

int main(){

    Node* root = NULL;
    cout<<"Enter data to create a BST"<<endl;

    takeInput(root);

    int element;
    cout<<"input the key ";
    cin>>element;

    return 0;
}