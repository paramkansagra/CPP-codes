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
void levelOrderTraversal(queue<Node*> q){
    if(q.empty()){
        return ;
    }

    queue<Node*> q2;
    queue<Node*> q1;
    while(!q.empty()){
        Node* temp = q.front();
        q1.push(temp);
        q.pop();

        if(temp->left != NULL){
            q2.push(temp->left);
        }
        if(temp->right != NULL){
            q2.push(temp->right);
        }
    }

    levelOrderTraversal(q2);

    while(!q1.empty()){
        Node* temp = q1.front();
        q1.pop();

        cout<<temp->data<<" ";
    }cout<<endl;
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

    queue<Node*> q;
    q.push(root);

    cout<<"level order traversal"<<endl;
    levelOrderTraversal(q);

    return 0;
}