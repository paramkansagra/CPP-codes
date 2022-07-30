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

// for a balanced tree there are 2 conditions first is that all nodes need to have diffrence in height
// of only 1(at max)
bool isBalanced(Node* root){
    if(root == NULL){
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diffrence = getHeightOfTree(root->left)-getHeightOfTree(root->right) <= 1;

    if(left && right && diffrence){
        return true;
    }
    return false;
}

// O(n) solution cause we are not calling height for each and every node
pair<bool,int> isBalancedFast(Node* root){ // here we wont be calling height for all the nodes
    if(root == NULL){ // so if the root is NULl then it is balanced and height is 0
        pair<bool,int> ans = make_pair(true,0); // making pair for the same
        return ans; // return it
    }

    pair<bool,int> left = isBalancedFast(root->left); // making pair for the left
    pair<bool,int> right = isBalancedFast(root->right); // making pair for the right
    
    bool leftAns = left.first; // left ka node is balanced or not
    bool rightAns = right.first; // right ka node is balanced or not

    bool differnceHeight = abs(left.second-right.second) <= 1; // is the diffrence of height less than or equal to 1

    pair<bool,int> ans; // making the pair to be returned

    if(leftAns && rightAns && differnceHeight){ // if all of them are true then ab tak sab balanced hai
        ans.first = true; // so ans.first will be true
    }
    else{ // else it will be false
        ans.first = false;
    }

    ans.second = max(left.second,right.second)+1; // ans.second is the height value which is the max of left and right +1

    return ans; // returning the ans
}


int main(){

    Node* root = NULL;

    // creating a tree
    root = buildTree(root);

    if(isBalancedFast(root).first){
        cout<<"it is a balanced tree";
    }
    else{
        cout<<"it is a unbalanced tree";
    }

    return 0;
}