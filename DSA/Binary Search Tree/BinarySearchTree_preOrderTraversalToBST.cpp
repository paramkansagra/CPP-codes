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

Node* solve(vector<int> preOrderTraversal,int mini,int maxi,int &index){
    if(index>=preOrderTraversal.size()){
        return NULL;
    }

    if(preOrderTraversal[index]<mini || preOrderTraversal[index]>maxi){
        return NULL;
    }

    Node* root = new Node(preOrderTraversal[index++]);
    root->left = solve(preOrderTraversal,mini,root->data,index);
    root->right = solve(preOrderTraversal,root->data,maxi,index);

    return root;
}

// so this function is the start for turning the preOrderTraversal to BST
// so the process this will follow is we will have the index
// if it is greater than the mini(set by the prevElement) and smaller than the maxi(set by the prevElement)
// we will make a node and then increase the index of the vector
// now we can go in the left of this tree setting the maxi = node->data and mini as it was (as the mini for the BST remains the same but the max value cant be greater than that of the parent node)
// now we can go in the right of the tree setting the mini = node->Data and maxi as it was

// if the preOrderTraversal is smaller than the mini or it is greater than the maxi then return NULL
Node* preOrderToBST(vector<int> preOrderTraversal){
    int index = 0;
    int mini = INT_MIN;
    int maxi = INT_MAX;

    return solve(preOrderTraversal,mini,maxi,index);
}

// doing a level order traversal of the tree 
void print(Node* root){
    stack<Node*> st; // making a stack for level order traversal
    st.push(root); // pushing the root as the first element in the stack

    while(!st.empty()){
        int size = st.size(); // for that stack view we will find the size of the stack
        for(int i=0;i<size;i++){
            Node* front = st.top(); // pull out the top element of the stack
            st.pop(); // and pop it out

            cout<<front->data<<" "; // print the front element
            if(front->left != NULL){ // if the left of the element is non null then push in the stack
                st.push(front->left);
            }
            if(front->right != NULL){ // if the right of the element is non null then push in the stack
                st.push(front->right);
            }
        }
        cout<<endl; // print endl when the on level order is finished
    }
}

int main(){

    vector<int> preOrder;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;

        preOrder.push_back(temp);
    }

    Node* root = preOrderToBST(preOrder);
    print(root);

    return 0;
}