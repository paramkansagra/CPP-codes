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

bool validateBST(Node* root,int min,int max){
    if(root == NULL){ // if the root is null then it is a valid bst
        return true; 
    }

    // else check if the left is okay and right is okay

    if(root->data > min && root->data < max){
        bool left = validateBST(root->left,min,root->data);
        bool right = validateBST(root->right,root->data,max);

        if(left && right){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

int main(){

    Node* root = NULL;
    cout<<"Enter data to create a BST"<<endl;

    takeInput(root);

    if(validateBST(root,INT_MIN,INT_MAX)){
        cout<<"valid bst"<<endl;
    }
    else{
        cout<<"invalid bst"<<endl;
    }

    return 0;
}