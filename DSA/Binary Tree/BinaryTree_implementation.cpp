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


// in InOrderTraversal we have LNR format -> left node right format
// and we are going to print the same
void InOrderTraversal(Node* root){
    if(root->left != NULL){
        InOrderTraversal(root->left);
    }
    cout<<root->data<<" ";
    if(root->right != NULL){
        InOrderTraversal(root->right);
    }
}


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


// we would be using queue for traversing the tree
// this is called deapth first search
void levelOrderTraversal(Node* root){
    queue<Node*> q;

    q.push(root);
    // to show the tree in a tree format for printing we have to add a seprator for each level
    q.push(NULL); // here the seprator is NULl 

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){ // agar NULL aa gaya hai then old level complete ho gaya hai
            cout<<endl;
            if(!q.empty()){ // matlab kuch child nodes hai
                q.push(NULL); // next level ke lie push kar do NULL ko so that pata chale ki konsa level kaha khatam ho raha hai
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
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

// in PostOrderTraversal we have NLR format -> left right node format
// and we are going to print the same
void PostOrderTraversal(Node* root){
    if(root->left != NULL){
        PostOrderTraversal(root->left);
    }
    
    if(root->right != NULL){
        PostOrderTraversal(root->right);
    }

    cout<<root->data<<" ";
}

Node* buildTreeFromLevelOrder(Node* &root){
    queue<Node*> q;

    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;

    root = new Node(data);

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"enter left node for "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new Node(leftData);
            q.push(temp->left);
        }

        cout<<"enter right node for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main(){

    Node* root = NULL;

    // creating a tree
    buildTreeFromLevelOrder(root);

    // printing the tree
    levelOrderTraversal(root);

    return 0;
}