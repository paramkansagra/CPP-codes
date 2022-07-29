#include <iostream>
#include <queue>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

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

// building in a recursive way
Node* buildTree(Node* root){

    cout<<"Enter data for the node ";
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }
    cout<<"Enter data for inserting in the left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data for inserting in the right of "<<data<<endl;
    root->right = buildTree(root->right);

}

int main(){

    Node* root = NULL;

    // creating a tree
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // level order traversal

    cout<<"level order traversal"<<endl;
    levelOrderTraversal(root);

    return 0;
}