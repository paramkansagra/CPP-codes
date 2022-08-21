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

void preOrderTraversal(Node* root){
    if(root == NULL){
        return ;
    }

    cout<<root->data<<" ";

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
    if(root == NULL){
        return ;
    }

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root == NULL){
        return ;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

int main(){

    Node* root = NULL;
    cout<<"Enter data to create a BST"<<endl;

    takeInput(root);

    cout<<"level Order Traversal"<<endl;
    levelOrderTraversal(root);
    
    cout<<"in order traversal"<<endl;
    inOrderTraversal(root);
    cout<<endl;

    cout<<"pre order traversal"<<endl;
    preOrderTraversal(root);
    cout<<endl;

    cout<<"post order traversal"<<endl;
    postOrderTraversal(root);
    cout<<endl;   

    return 0;
}