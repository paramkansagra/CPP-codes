#include <bits/stdc++.h>
 
using namespace std;
 
class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(){
            this->data = -1;
            this->left = NULL;
            this->right = NULL;
        }

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node* root,int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    Node* temp = new Node(data);

    // root ke right part me the data is greater than the root
    // root ke left part me the data is great than that of the root

    if(data > root->data){
        // right part me jao and insert the data recursively
        root->right = insertIntoBST(root->right,data);
    }
    else{ 
        // left part me jao and insert the data recursively
        root->left = insertIntoBST(root->left,data);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

// we are doing the inOrderTraversal in a recursive way
// if the root is NULL then end the function and return ;
// else we have to go in a LNR way
// first go in the left node and append
// then append the root node value
// then go in the right node and append
void inOrder(Node* root,vector<int> &inOrderTraversal){
    if(root == NULL){
        return ;
    }

    inOrder(root->left,inOrderTraversal);
    inOrderTraversal.push_back(root->data);
    inOrder(root->right,inOrderTraversal);
}


// given a bst and a target value
// we have to find if there exists any 2 nodes such that its sum equals to the target value
bool twoSumInBST(Node* root,int target){
    vector<int> inOrderTraversal; // so we will do a inOrderTraversal as we know that in an inOrderTraversal the bst comes out to be a sorted array
    inOrder(root,inOrderTraversal);

    // so we will then make a two pointer approch and then check if the sum of the both is equal to target
    // if it is equal to target then return true;
    // if it is smaller than target then increase the value of i
    // if it is greater than target then decrease the value of j
    // if there exists no case like this then return false;

    int i = 0;
    int j = inOrderTraversal.size()-1;

    while(i<j){
        int sum = inOrderTraversal[i]+inOrderTraversal[j];
        if(sum == target){
            return true;
        }
        else if(sum>target){
            j--;
        }
        else{
            i++;
        }
    }
    
    return true;
}

int main(){

    Node* root = NULL;
    cout<<"Enter data to create a BST"<<endl;

    takeInput(root);

    int k;
    cin>>k;

    if(twoSumInBST(root,k)){
        cout<<"target sum found"<<endl;
    }
    else{
        cout<<"target sum not found"<<endl;
    }

    return 0;
}