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

// we are finding the inOrderTraversal of a bst
void inOrder(Node* root,vector<int>& inOrderTraversal){
    if(root == NULL){ // the base case is if the root is null then end the function and return 
        return ;
    }

    inOrder(root->left,inOrderTraversal); // so for a inOrderBST we have to first go in the left node
    inOrderTraversal.push_back(root->data); // then add the root node into the vector
    inOrder(root->right,inOrderTraversal); // then go in the right side of the node
}

Node* inOrderToBST(int start,int end,vector<int> inOrderTraversal){
    // base case
    if(start>end){ // if the starting index is greater than the ending index then return NULL
        return NULL;
    }

    int mid = start + (end-start)/2; // finding the mid to get the mid element
    Node* root = new Node(inOrderTraversal[mid]); // making a new node for the mid Element

    root->left = inOrderToBST(start,mid-1,inOrderTraversal); // now we have to go in the left side of the array for the left of the BST
    root->right = inOrderToBST(mid+1,end,inOrderTraversal); // now we have to go in the right side of the array for the right side of the BST

    return root; // returning the root
}

// in this function we will be changing a normal BST to a balanced BST
Node* normalBSTtoBalancedBST(Node* root){
    vector<int> inOrderTraversal; // first we are finding the inOrderTraversal of the BST
    inOrder(root,inOrderTraversal);

    // so the process followed here is 
    // we know that the inOrderTraversal of the bst is sorted
    // so we will pick up the mid node and make it as a root
    // the left side of the root is the left side of the array
    // the right side of the root is the right side of the array

    Node* ans = inOrderToBST(0,inOrderTraversal.size()-1,inOrderTraversal);
    return ans;
}

// we are printing the bst using the levelOrderTraversal
void print(Node* root){
    while(root == NULL){ // if the root is null then no need to print the bst
        return ; // ending the function
    }

    stack<Node*> st; // making a stack for the levelOrderTraversal
    st.push(root); // pushing the root first

    while(!st.empty()){ // we have to keep printing till the stack is empty
        int size = st.size(); // taking the size of the stack as we have to print levelOrderTraversal
        for(int i=0;i<size;i++){ 
            Node* front = st.top(); // first finding the front node of the stack
            st.pop(); // poping it out 

            cout<<front->data<<" "; // print the data of the front node
            if(front->left != NULL){ // if the left side of the front is nonNULL push in the stack
                st.push(front->left);
            }
            if(front->right != NULL){ // if the right side of the front is nonNULL push in the stack
                st.push(front->right);
            }
        }
        cout<<endl; // give a endl for that level order look
    }

}

int main(){

    Node* root = NULL;
    cout<<"Enter data to create a BST"<<endl;

    takeInput(root);

    root = normalBSTtoBalancedBST(root);
    print(root);

    return 0;
}