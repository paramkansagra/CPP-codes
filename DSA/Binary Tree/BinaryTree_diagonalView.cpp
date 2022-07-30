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

void solve(Node* root,map<int,vector<int>>& diagonalView,int slope){
    if(root == NULL){ // base case i.e. if the root is null then end the function and return ;
        return ;
    }

    // ek case sambhalo
    diagonalView[slope].push_back(root->data); // first store the value of the current node in the respective vector
    
    // dusra sab recursion sambhal lega
    solve(root->left,diagonalView,slope+1); // go in the left side and increase the value of slope by 1
    solve(root->right,diagonalView,slope); // go in the right side and keep the value of slope as it is 
}

// so we want the diagonal view of the tree
// we would be doing the same recursively
// we would assume that when we go to the right of the tree the slope wont change
// but when we go to the left of the tree the slope increases by 1
// now we can use a map and store all the elements of same slope 
// then pull out the elements from the slope of each element and push into a answer vector
// and then return the answer vector
void diagonalViewOfTree(Node* root,vector<int>& ans){
    map<int,vector<int>> diagonalView; // making a map storing the slope as the key and vector<int> storing the values of the nodes with that slope
    solve(root,diagonalView,0); // initial base case where the slope of the root node is 0 and we are going in the tree

    for(auto i:diagonalView){ // now after the map is updated we will go in the map
        for(auto j:i.second){ // taking the second part of the map i.e. the vector and going into that as we are interested in the values of the nodes of a particular slope
            ans.push_back(j); // pushing the values of the nodes into the answer vector
        }
    }
}

void print(Node* root){ // bring the root node for the printing
    vector<int> ans; // pull the answer vector from the diagonalViewOfTree
    diagonalViewOfTree(root,ans);
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