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


// so we have to check the lowest common ancestor
// so what we will do is go in the left node and go in the right node and check if n1 or n2 is present
// so 4 cases can be there 1->n1 is there but n2 is not there for a node -> return n1
// 2-> n2 is there but n1 is not there for the node -> return n2
// 3-> n1 and n2 both are present for the node -> return that node
// 4-> none of n1 or n2 is present for the node -> return NULL
Node* lowestCommonAncestor(Node* root,int n1,int n2){
    if(root == NULL){ // if the root is NULL return NULL
        return NULL;
    }

    if(root->data == n1 || root->data == n2){ // now check if the node is equal to n1 or n2
        return root; // if yes then retuen the node
    }

    Node* leftAns = lowestCommonAncestor(root->left,n1,n2); // check for the leftSide
    Node* rightAns = lowestCommonAncestor(root->right,n1,n2); // check for the rightSide

    if(leftAns != NULL && rightAns != NULL){ // if none of them is NULL return root
        return root;
    }
    else if(leftAns != NULL && rightAns == NULL){ // if leftAns is non NULL but rightAns is NULL
        return leftAns; // return leftAns
    }
    else if(leftAns == NULL && rightAns != NULL){ // if leftAns is NULL but rightAns is non NULL
        return rightAns; // return rightAns
    }
    else{
        return NULL; // if both of them are NULL return NULL
    }
}

int main(){

    Node* root = NULL;

    // creating a tree
    root = buildTree(root);

    int n1,n2; // input the n1 and n2 to be searched 
    cin>>n1>>n2;

    Node* ans = lowestCommonAncestor(root,n1,n2); // get the node that is the LCA

    cout<<ans->data<<endl; // print the data of that node

    return 0;
}