#include <iostream>
#include <queue>
#include <map>

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

// in a binary tree we have a mapping for parent to nodes but we dont have mapping for node to parents
// in burining a tree we need mapping from node to parent so we will be creating that
// this function will also return the targetNode i.e. the node from which the burning will start
Node* nodeToParentMapping(Node* root,int target,map<Node*,Node*> nodeToParent){
    // creating a result targetNode for returning
    Node* targetNode = NULL; // setting it null initially to not let it point anywhere

    // making a queue as we will be doing inOrderTraversal
    queue<Node*> q;
    q.push(root); // initially pushing root into the queue

    // making the root ka parent as NULL
    nodeToParent[root] = NULL;

    // doing inOrderTraversal
    while(!q.empty()){
        // bring the front node of the queue and pop it out
        Node* front = q.front();
        q.pop();

        // checking if the front is equal to the target
        if(front->data == target){
            targetNode = front;
        }

        // making the mapping for the node and parent
        if(front->left != NULL){
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if(front->right != NULL){
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }

    return targetNode; // returing the targetNode
}

void burnTree(Node* root,int& ans,map<Node*,Node*>& nodeToParent){
    // now we will be making 2 new dataStructures
    // first is for checking if the node is visited or not => if the node is visited then we wont go there as it is burnt already
    // second is for what nodes we need to traverse for travelling the node

    map<Node*,bool> visited; // this is the data structure if the node is visited or not
    queue<Node*> q; // making a queue for doing the actual inOrderTraversing

    q.push(root); // initially pushing the root node into the queue
    visited[root] = true; // and making the visited of the root as true as thats actually from where the burining is starting

    while(!q.empty()){
        // now we will be doing finding the size of the queue as we need to traverse it
        int size = q.size();
        bool flag = false; // we are making a bool to check if has burnt any more nodes or not

        for(int i=0;i<size;i++){
            Node* front = q.front(); // doing inOrderTraversal
            q.pop();

            if(front->left != NULL && !visited[front->left]){
                flag = true; // making the flag as true as we burnt a node
                visited[front->left] = true; // making the front left node as travelled
                q.push(front->left); // and pushing the actual node into the queue for further traversal
            }

            if(front->right != NULL && !visited[front->right]){
                flag = true;
                visited[front->right] = true;
                q.push(front->right);
            }
            
            // now we know that burning can spred upwards as well
            // now if there is a parent node of the root node then we can burn that as well
            // so we will go in the parent node as well to burn it
            if(nodeToParent[front] != NULL & !visited[nodeToParent[front]]){
                flag = true;
                visited[nodeToParent[front]] = true;
                q.push(nodeToParent[front]);
            }
        }

        if(flag == true) ans++;
    }
}

int main(){

    // build a tree
    Node* root = NULL;
    root = buildTree(root);

    int target = -1;
    cin>>target;

    Node* targetNode = NULL;

    // creating the mapping
    map<Node*,Node*> nodeToParent;
    targetNode = nodeToParentMapping(root,target,nodeToParent);
    
    int ans = 0;
    burnTree(targetNode,ans,nodeToParent);

    cout<<ans<<endl;

    return 0;
}