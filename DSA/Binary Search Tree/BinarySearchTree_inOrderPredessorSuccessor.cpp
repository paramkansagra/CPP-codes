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

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}

Node* find(Node* root,int element){
    if(root == NULL){
        return NULL;
    }

    if(root->data == element){
        return root;
    }

    Node* left = find(root->left,element);
    Node* right = find(root->right,element);

    if(left == NULL && right == NULL){
        return NULL;
    }
    else if(left != NULL && right == NULL){
        return left;
    }
    else{
        return right;
    }
}

Node* inOrderPred(Node* root,int element){
    Node* findElement = find(root,element);

    if(findElement == NULL || findElement->left == NULL){
        return NULL;
    }

    // in order predessor is the right most node in the left sub tree
    findElement = findElement->left;
    
    while(findElement->right != NULL){
        findElement = findElement->right;
    }

    return findElement;
}

Node* inOrderSuc(Node* root,int element){
    Node* findElement = find(root,element);

    if(findElement == NULL || findElement->right == NULL){
        return NULL;
    }

    // in order sucessor is the left most element in the right sub tree
    findElement = findElement->right;

    while(findElement->left != NULL){
        findElement = findElement->left;
    }
    return findElement;
}

int main(){

    Node* root = NULL;
    cout<<"Enter data to create a BST"<<endl;

    takeInput(root);

    int element;
    cout<<"input the key ";
    cin>>element;

    Node* predessor = inOrderPred(root,element);
    Node* successor = inOrderSuc(root,element);

    cout<<"inorder predessor is "<<predessor->data<<endl;
    cout<<"inorder successor is "<<successor->data<<endl;

    return 0;
}