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

// time complexity O(n^2) => O(n)->for diameter of tree * O(n)->height of tree
// here we will be finding the diameter of a tree
// so diameter is the longest path in a tree
int getDiameterOfTree(Node* root){
    // doing it recursively the base condition is if the root is NULL return 0
    if(root == NULL){
        return 0;
    }

    // now there are 3 ways to get the max diameter of a tree
    // first is to go to the left and find the diameter
    // second is to go in the right and find the diameter
    // thrid is to get the combo of the both -> height of left + height of right + 1(cause root node is also considered)

    int left = getDiameterOfTree(root->left); // going in the left of the tree
    int right = getDiameterOfTree(root->right); // going in the right of the tree
    int combo = getHeightOfTree(root->left) + getHeightOfTree(root->right) + 1; // doing the combo

    return max(max(left,right),combo);
}

// O(n) method
pair<int,int> diameterFast(Node* root){
    if(root == NULL){
        pair<int,int> ans = make_pair(0,0);
        return ans;
    }

    // the first int is having the diameter of the tree
    // the second int of the tree is showing the height of the tree

    pair<int,int> left = diameterFast(root->left); // left node ka diameter and height
    pair<int,int> right = diameterFast(root->right); // right node ka diameter and height

    int op1 = left.first; // op1 is the left node ka diameter
    int op2 = right.first; // op2 is the right node ka diameter
    int op3 = left.second + right.second + 1; // op3 is the max height of the nodes

    pair<int,int> ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second,right.second)+1;

    return ans;
}

int getDiameterOfTree2(Node* root){

    return diameterFast(root).first; // find the diameter of the tree
}

int main(){

    Node* root = NULL;

    // creating a tree
    root = buildTree(root);

    int ans = getDiameterOfTree(root);

    cout<<ans<<endl;

    return 0;
}