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

int solve(Node* root,int k,int node,vector<int> path){
    if(root == NULL){ // base condition if the root node is null then return -1
        return -1;
    }

    if(root->data == node){ // if the root->data is same as the node meaning the node is found
        if(path.size()<k){ // if the path size is smaller than k
            return -1; // then we return -1
        }
        else{
            return path[path.size()-k]; // else we will just return the kth node from behind in the path vector
        }
    }

    path.push_back(root->data); // push the current root data in the path vector so that we have the trail to the path
    
    int left = solve(root,k,node,path); // we will go in the left side and check if there is any node present
    int right = solve(root,k,node,path); // we will go in the right side and check if there is any node present
    
    path.pop_back(); // removing the last element // backtracking

    if(left != -1){ // if the left side is not -1 meaning the node is present there 
        return left; // return left side then
    }
    else if(right != -1){ // if the right side is not -1 meaning the node is present on right side
        return right; // return the right side then
    }
    else{
        return -1; // if node is not present on either side then return -1
    }
}

// now we have to find the kth ancestor of a node
// now to solve this we can make a vector that is storing the path till a leaf node
// if we find the node then we can just return the k nodes before it
// if there is no node like this we will return -1
int kthAncestor(Node* root,int k,int node){
    vector<int> path; // making a vector path to store the path till a node
    int ans = solve(root,k,node,path); // making a ans variable to store the answer pulled from solve function
    return ans; // return the ans
}

int main(){

    Node* root = NULL;

    // creating a tree
    root = buildTree(root);

    int k,node;
    cin>>k>>node;

    int ans = kthAncestor(root,k,node);

    cout<<ans<<endl;

    return 0;
}