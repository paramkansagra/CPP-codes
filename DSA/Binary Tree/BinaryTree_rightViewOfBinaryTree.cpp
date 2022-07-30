#include <iostream>
#include <queue>
#include <vector>
#include <map>

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

void rightViewOfTree(Node* root,vector<int>& ans,int level){
    if(root == NULL){ // if the root is null then return and end the function
        return ;
    }
    
    if(level == ans.size()){ // jab level is equal to the answer vector ka size then push the root data into the vector
        ans.push_back(root->data);
    }
    
    rightViewOfTree(root->right,ans,level+1); // go in the right side of the tree
    rightViewOfTree(root->left,ans,level+1); // go in the left side of the tree
}

void print(Node* root){ // bring the root node for the printing
    vector<int> ans; // pull the answer vector from the rightViewOfTree
    rightViewOfTree(root,ans,0);
    for(int i=0;i<ans.size();i++){ // print the answer vector
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