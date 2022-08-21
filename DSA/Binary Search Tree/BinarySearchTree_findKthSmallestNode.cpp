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

int findKthSmallestNode(Node* root,int k,int& i){
    if(root == NULL){
        return -1;
    }

    int left = findKthSmallestNode(root->left,k,i);
    if(left != -1){
        return left;
    }

    i++;
    if(k == i){
        return root->data;
    }

    int right = findKthSmallestNode(root->right,k,i);
    return right;
}

int main(){

    Node* root = NULL;
    cout<<"Enter data to create a BST"<<endl;

    takeInput(root);

    int k,i;
    cin>>k;

    i = 0;
    int ans = findKthSmallestNode(root,k,i);
    cout<<ans<<endl;

    return 0;
}