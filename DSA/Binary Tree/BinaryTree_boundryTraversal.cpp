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

void traverseLeft(Node* root,vector<int>& ans){
    if(root == NULL || (root->left == NULL && root->right == NULL)){ // if the root node is NULL or if it is a leaf node then return
        return ; // leaf node => the left and right of the node will be NULL
    }

    ans.push_back(root->data); // pushing the root data now cause we dont want it in reverse format

    if(root->left != NULL){ // if the left of the node is not NULL then go in that 
        traverseLeft(root->left,ans);
    }
    else{ // else go in the right cause thats the boundry of the tree at the end of the day
        traverseLeft(root->right,ans);
    }
}

void traverseLeafNode(Node* root,vector<int>& ans){
    // now if the root is null then end the function there
    if(root == NULL){
        return ;
    }

    // else if the node is leaf node push the data in the vector and return
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
    }

    // now we have to follow Left Node Right format for traversing the tree
    // as the boundry is going from left to right so 
    traverseLeafNode(root->left,ans);
    traverseLeafNode(root->right,ans);
}

void traverseRight(Node* root,vector<int>& ans){
    // now if the root node is null end the function
    if(root == NULL || (root->left == NULL && root->right == NULL)){ // or else if the node is leaf node then also end the function
        return ; // leaf node => its left and right node will be NULL
    }

    if(root->right != NULL){ // now if the right side of the tree is non NULL then go in that
        traverseRight(root->right,ans); // call the function here
    }
    else{ // else go in the left side as at the end of the day it is the boundry of the tree
        traverseRight(root->left,ans);
    }

    ans.push_back(root->data); // we are pushing the data at the end as we need the data in a reverse order
    // and if we push the data after the functions are called it will come in reverse order
    // cause the functions will call it self and push their later elements first and then when those functions are over we will push our element
}

vector<int> boundryTraversal(Node* root){
    // now boundry traversal has 3 parts
    // traverse the left part and dont include the leaf nodes
    // traverse all the leaf nodes in Left Node Right format
    // traverse the right part and reverse it and dont include the leaf nodes

    vector<int> ans; // making a ans vector to return ans
    if(root == NULL){ // if the root is empty return the empty vector
        return ans;
    }

    ans.push_back(root->data); // pushing the root data in the beginning

    // traverse the left part
    traverseLeft(root->left,ans);

    // now traverse the leaf nodes of left and right parts
    traverseLeafNode(root->left,ans);
    traverseLeafNode(root->right,ans);

    // now traverse the right part in a reverse order
    traverseRight(root->right,ans);

    return ans;
}

void print(Node* root){
    vector<int> ans = boundryTraversal(root);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;
}

int main(){

    Node* root = NULL;
    
    // creating a tree
    root = buildTree(root);
    
    print(root);
    
    return 0;
}