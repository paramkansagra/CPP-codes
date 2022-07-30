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

Node* solve(Node* root,int k,int node){
    if(root == NULL){ // base condition if the root node is null then return -1
        return NULL;
    }

    if(root->data == node){ // now if the node is equal to what we are finding then we will return the node
        return root;
    }
    
    Node* left = solve(root->left,k,node); // now we will go in the left side and search
    Node* right = solve(root->right,k,node); // now we will go in the right side and search
    
    if(left != NULL){ // agar left side vala non NULL hai
        k--; // then reduce k and check
        if(k<=0){ // if it is less than 0
            k = 99999; // then change the value of k to lock the result
            return root; // and return root
        }
        return left; // else return left node that we found
    }
    else if(right != NULL){ // agar right side vala non NULL hai
        k--; // then reduce the k and check
        if(k<=0){ // if it is less then 0
            k = 99999; // then change the value of k to lock the result
            return root; // and return root
        }
        return right; // else return right node that we found
    }
    else{
        return NULL; // else return NULL
    }
}

// now we have to find the kth ancestor of a node
// now to solve this we can make a vector that is storing the path till a leaf node
// if we find the node then we can just return the k nodes before it
// if there is no node like this we will return -1
int kthAncestor(Node* root,int k,int node){
    vector<int> path; // making a vector path to store the path till a node
    Node* ans = solve(root,k,node); // making a ans variable to store the answer pulled from solve function
    if(ans == NULL || ans->data == node){
        return -1;  
    } // return the ans
    else{
        return ans->data;
    }
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