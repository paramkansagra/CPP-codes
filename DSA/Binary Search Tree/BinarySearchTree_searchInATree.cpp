#include <iostream>
#include <stack>
 
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

void levelOrderTraversal(Node* root){
    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        int size = st.size();
        for(int i=0;i<size;i++){
            Node* front = st.top();
            st.pop();

            cout<<front->data<<" ";
            if(front->left != NULL){
                st.push(front->left);
            }
            if(front->right != NULL){
                st.push(front->right);
            }
        }
        cout<<endl;
    }
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}


// recursive approch
bool searchInBST1(Node* root,int element){
    if(root == NULL){ // if the root is null then no element present
        return false; // so return false;
    }

    // if the root's data == element
    if(root->data == element){
        return true; // then return true
    }

    // if the root's data is smaller than the element 
    if(root->data < element){ // then go in the right side and return 
        return searchInBST1(root->right,element);
    }

    // if the root's data is greater than the element 
    if(root->data > element){ // then go in the left side and return 
        return searchInBST1(root->left,element);
    }

    // time complexity => O(n)
    // space complexity => O(n) 
    // see the recursive tree for the space complexity
}

// searching in the bst in a iterative way
bool searchInBST(Node* root,int element){
    if(root == NULL){ // if the root is null
        return false; // return false
    }

    Node* curr = root; // make a curr node
    while(curr != NULL){ // go in the tree till curr is not null
        if(curr->data == element){ // if the curr's data is equal to element
            return true; // return true
        }
        if(curr->data < element){ // else if curr's data is smaller than the element
            curr = curr->right; // go in the right side
        }
        else{ // else if the curr's data is greater than the element
            curr = curr->left; // go in the left side
        }
    }
    return false; // if the curr becomes null and nothing is returned thn it return false
}

int main(){

    Node* root = NULL;
    cout<<"Enter data to create a BST"<<endl;

    takeInput(root);

    int element;
    cout<<"input element";
    cin>>element;

    if(searchInBST(root,element)){
        cout<<"element found"<<endl;
    }
    else{
        cout<<"element not found"<<endl;
    }

    return 0;
}