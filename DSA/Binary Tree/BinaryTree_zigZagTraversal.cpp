#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

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

vector<int> zigZagTraversal(Node* root){
    vector<int> ans; // making a vector ans to return 
    if(root == NULL){ // if the root is NULL then we will return the empty vector
        return ans; // returning empty vector
    }

    queue<Node*> q; // making a queue to keep track of what elements to process
    q.push(root); // pushing root node as the first node to start processing 

    bool leftToRight = true; // making a flag to see if we have to reverse the temp vector or not

    while(!q.empty()){ // we will run the while loop till the whole tree is traversed
        vector<int> temp; // making a vector temp to store the temporary elements in the vector
        int size = q.size(); // making a size variable to see how many elements to process
        // cause we will be pushing more and more elements in the queue
        // also we have to reverse some of them and not to some 
        // so we will process some elements in the queue which is equal to the 
        
        for(int i=0;i<size;i++){ // make a for loop from 0 to size 
            Node* frontElement = q.front(); // take the front element from the queue
            q.pop(); // and pop it out

            temp.push_back(frontElement->data); // and push the front element in the vector
            
            if(frontElement->left != NULL){ // also push the front element ka left in the queue
                q.push(frontElement->left);
            }
            if(frontElement->right != NULL){ // also push the front element ka right in the queue
                q.push(frontElement->right);
            }
        }

        if(leftToRight){ // if left se right then make it false
            leftToRight = false;
        }
        else{ // if it is false then reverse the temp vector
            reverse(temp.begin(),temp.end());
            leftToRight = true; // and make leftToRight as right
        }

        ans.insert(ans.end(),temp.begin(),temp.end()); // concatenate the 2 vectors and push out the answer
    }

    return ans; // return the answer vector
}

void print(Node* root){
    vector<int> ans = zigZagTraversal(root); // take the answer vector fron the zigZag function

    for(int i=0;i<ans.size();i++){ // print the elements of ans vector
        cout<<ans[i]<<" ";
    }cout<<endl;
}

int main(){

    Node* root = NULL;

    // creating a tree
    root = buildTree(root);

    print(root);

    return 0;
}