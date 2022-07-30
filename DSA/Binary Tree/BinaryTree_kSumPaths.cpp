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

void solve(Node* root,int k,int& count,vector<int> path){
    if(root == NULL){ // if the root is NULL return and end the function
        return ;
    }

    path.push_back(root->data); // pushBack the root->data in the vector path
    solve(root->left,k,count,path); // go in the left side of the tree
    solve(root->right,k,count,path); // go in the right side of the tree

    int sum = 0; // initialize sum as 0
    for(int i=path.size()-1;i>=0;i--){ // now go thru the vector from behind
        sum += path[i]; // and add to the sum
        if(sum == k){ // if the sum == k
            count++; // increase the count
        }
    }

    path.pop_back(); // remove the currentRoot value else it will be incuded in other paths
    // backTracking kinda
}

int kSumPaths(Node* root,int k){
    vector<int> path; // initilize the vector path
    int count = 0; // put the count to be zero
    solve(root,k,count,path); // call the solve function
    return count; // and return the count
}

int main(){

    Node* root = NULL;

    // creating a tree
    root = buildTree(root);

    int k;
    cin>>k;

    int ans = kSumPaths(root,k);

    cout<<ans<<endl;

    return 0;
}