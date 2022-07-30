#include <iostream>
#include <queue>
#include <vector>
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

// so top view of binary tree is done using inorder traversal
// we would be knowing the level as well as the position of the node in the number line and 
// we will see that there is only one passing for a position like -2 -1 0 1 2 and so on
// this can be done by creating a map and storing the values in the same

vector<int> topViewOfTree(Node* root){
    
    vector<int> ans; // making a answer vector to return 
    if(root == NULL){ // if the root is null then return empty vector
        return ans;
    }

    queue<pair<Node*,int>> q; // making a queue having a pair with first element as a Node and second element as the horizontalDistance
    q.push(make_pair(root,0)); // pushing the first element in the queue with root as the Node and horizontalDistance as 0

    map<int,int> topView; // making a map having horizontalDistance as key and int value of node as value

    while(!q.empty()){ // while the queue is not empty (inOrderTraversal)
        pair<Node*,int> front = q.front(); // pull the first element out of the queue
        q.pop(); // pop the first element out of the queue

        Node* frontElement = front.first; // take the front node element from the front variable
        int horizontalDistance = front.second; // take the horizonal distance fron the front variable

        if(topView.find(horizontalDistance) == topView.end()){ // check if a key value pair is present for a horizontal distance
            topView[horizontalDistance] = frontElement->data; // if it is not present then pass a new one
        }

        if(frontElement->left != NULL){ // if the left of a front element is there then push it into the queue with horizontalDistance-1
            q.push(make_pair(frontElement->left,horizontalDistance-1)); // normal inOrderTraversal
        }
        if(frontElement->right != NULL){ // if the right of a front element is there then push it into the queue with horizontalDistance+1
            q.push(make_pair(frontElement->right,horizontalDistance+1)); // normal inOrderTraversal
        }
    }

    for(auto i:topView){ // now go in the map and pull all the second values i.e. node values out of the map
        ans.push_back(i.second); // pushing in the answer vector
    }

    return ans; // return the answer vector
}

void print(Node* root){ // bring the root node for the printing
    vector<int> ans = topViewOfTree(root); // pull the answer vector from the topViewOfTree
    for(int i=0;i<ans.size();i++){ // print the answer vector
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