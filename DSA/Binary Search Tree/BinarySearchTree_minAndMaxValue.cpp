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

Node* minValue(Node* root){
    if(root == NULL){
        return NULL;
    }

    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

Node* maxValue(Node* root){
    if(root == NULL){
        return NULL;
    }

    while(root->right != NULL){
        return root;
    }
}

int main(){

    Node* root = NULL;
    cout<<"Enter data to create a BST"<<endl;

    takeInput(root);

    Node* min = minValue(root);
    Node* max = maxValue(root);

    cout<<"min value of the BST is "<<min->data<<endl;
    cout<<"max value of the BST is "<<max->data<<endl;

    return 0;
}