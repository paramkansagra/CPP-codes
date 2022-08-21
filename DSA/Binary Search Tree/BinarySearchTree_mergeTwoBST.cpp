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

// here we are finding out the inOrderTraversal of the BST
void inOrder(Node* root,vector<int>& arr){
    if(root == NULL){ // if the root is NULL then end the function and return 
        return ;
    }

    inOrder(root->left,arr); // else go in the left part and append the data
    arr.push_back(root->data); // append this node's data
    inOrder(root->right,arr); // go in the right part and append the data
}

// here we will be merging 2 vectors using a two pointer approch
vector<int> mergeArray(vector<int> arr1,vector<int> arr2){
    vector<int> ans; // make an ans vector
    int size1 = arr1.size(); // make size1 and size2 for storing the size of arr1 and arr2
    int size2 = arr2.size();

    int i = 0; // the first pointer for vector 1
    int j = 0; // the second pointer for vector 2

    while(i<size1 && j < size2){ // keep the loop working till these conditions are not achived
        if(arr1[i] < arr2[j]){ // if the arr1[i] < arr2[j] then push the first to the answer array
            ans.push_back(arr1[i++]); // and increase the value of i
        }
        else{ // if the arr2[j] < arr1[i] then push the second to the answer array
            ans.push_back(arr2[j++]); // and increase the value of j
        }
    }

    while(i<size1){ // if there are some elements present in array 1 then push it into the answer array
        ans.push_back(arr1[i++]);
    }
    while(j<size2){ // if there are some elements present in arr2 then push it into the answer array
        ans.push_back(arr2[j++]);
    }

    return ans; // return the ans array
}

// 
Node* makeBST(vector<int> arr,int start,int end){
    if(start>end){
        return NULL;
    }

    int mid = start + (end-start)/2;
    Node* root = new Node(arr[mid]);

    root->left = makeBST(arr,start,mid-1);
    root->right = makeBST(arr,mid+1,end);

    return root;
}

Node* mergeTwoBST(Node* root1,Node* root2){
    vector<int> inOrder1,inOrder2;
    inOrder(root1,inOrder1);
    inOrder(root2,inOrder2);

    vector<int> arr = mergeArray(inOrder1,inOrder2);

    Node* ans = makeBST(arr,0,arr.size()-1);
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


    return 0;
}