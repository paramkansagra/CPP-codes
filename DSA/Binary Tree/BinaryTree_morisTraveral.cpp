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

void morrisTraversal(Node* root){
    Node* curr = root;

    if(curr == NULL){
        return ;
    }

    while(curr != NULL){
        if(curr->left == NULL){
            cout<<curr->data<<' ';
            curr = curr->right;
        }
        else{
            Node* pred = findPredessor(curr);
            if(pred->right != NULL){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                pred->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}

int main(){

    Node* root = NULL;
    root = buildTree(root);

    morrisTraversal(root);

    return 0;
}