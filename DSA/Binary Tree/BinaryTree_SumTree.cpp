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

// O(n) time complexity
pair<bool,int> isSumTreeFast(Node* root){ // making a pair for effecient work
    if(root == NULL){ // if the root is null then it is a sum tree 
        pair<bool,int> ans = make_pair(true,0); // so the ans pair would be true and 0 cause it is a sum tree and sum of the tree is 0
        return ans;
    }

    if(root->left == NULL && root->right == NULL){ // if it is a leaf node then also we will return 
        pair<bool,int> ans = make_pair(true,root->data); // it is a sum tree so pair would be true and data of the node
        return ans;
    }

    pair<bool,int> left = isSumTreeFast(root->left); // now bring the left side of the root
    pair<bool,int> right = isSumTreeFast(root->right); // and bring the right side of the root

    bool leftAns = left.first; // leftAns will bring if the left side is a sum tree or not
    bool rightAns = right.first; // rightAns will bring if the right side is a sum tree or not

    bool isSumCondition = root->data == (left.second + right.second); // sum condition is that the root data must be equal to the sum of the left node side sum and right node side sum

    pair<bool,int> ans; // making an answer pair for returning

    if(leftAns && rightAns && isSumCondition){ // if all the conditions i.e. left side right side and the isSumCondition are true then make the answer
        ans.first = true; // meaning this node is also a sum tree
        ans.second = root->data*2; // and the second of the root will have the sum of the node as well as the left side and the right side essentially root->data * 2 // simple maths
    }
    else{
        ans.first = false; // else if any of the condition is not met then answer.first will be false meaning it is not a sum tree
    }

    return ans; // return the ans
}

bool isSumTree(Node* root){
    return isSumTreeFast(root).first; // returning if the root is a sum tree or not // we dont need to know the sum
}

int main(){

    Node* root = NULL;

    // creating a tree
    root = buildTree(root);

    if(isSumTree(root)){
        cout<<"it is a sum tree"<<endl;
    }
    else{
        cout<<"it is not a sum tree"<<endl;
    }

    return 0;
}