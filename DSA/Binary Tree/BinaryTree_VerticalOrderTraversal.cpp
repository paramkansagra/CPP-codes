#include <iostream>
#include <queue>
#include <map>
#include <vector>

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

// we would be doing vertical order traversal of a tree
// imagine a number line with the starting element as zero which is on the root node
// now if we go left or right then it is a -1 or +1 on the number line
// and we can also go down in the level of tree
vector<int> verticalOrderTraversal(Node* root){
    
    vector<int> ans; // making a answer vector
    if(root == NULL){ // if the root node is NULL
        return ans; // return the empty vector
    }

    map<int,map<int,vector<int>>> nodes; // now this map is containing the horizontal distance as the key in the first map 
    // and in the second map first int is the level of the of the binary tree and second vector is storing the elements in the vector
    
    queue<pair<Node*,pair<int,int>>> q; // now this queue will be storing a pair where the first one is storing the Node and second one is horizontal distance and the level of the particular node

    q.push(make_pair(root,make_pair(0,0))); // the first node is root having the horizontal level as 0 and the verical level as 0

    while(!q.empty()){ // now run the queue till it is not empty
        pair<Node*,pair<int,int>> front = q.front(); // so we will be pulling out the first big pair from the queue containing the node horizontalDistance and the vertical level

        q.pop(); // we have to pop the front element to not go in infinite loops

        Node* frontElement = front.first; // now pull out the Node from the pair as the pair's first element is the node
        int horizontalDistance = front.second.first; // now pull out the horizontal distance which is the pair's second's first element
        int verticalLevel = front.second.second; // now pull out the vertical level which is the pair's second's second element

        nodes[horizontalDistance][verticalLevel].push_back(frontElement->data); // now we will be pushing the node's data in the map containg the vertical level and the horizontal distance for the binary tree

        if(frontElement->left != NULL){ // now we will be going in the left of the node so horizontalDistance-1 and verticalLevel+1
            q.push(make_pair(frontElement->left,make_pair(horizontalDistance-1,verticalLevel+1))); // push the pair into the queue where the frontNode->left horizontalDistance-1 and verticalLevel+1
        }
        if(frontElement->right != NULL){ // now we will be going in the right of the node so horizontalDistance+1 and verticalLeve+1
            q.push(make_pair(frontElement->right,make_pair(horizontalDistance+1,verticalLevel+1))); // push the pair into the queue where the frontNode->right horizontalDistance+1 and verticalLevel+1
        }
    }

    for(auto i:nodes){ // now we will be going in the map where i is <int,map> 
        for(auto j:i.second){ // now we want to go in the map so j is now map<int,vector<int>>
            for(auto k:j.second){ // now we have to go in the vector so k is now vector<int>
                ans.push_back(k); // and push the k in the answer vector
            }
        }
    }

    return ans; // return the answer vector

}

void print(Node* root){ // printing the answer vector
    vector<int> ans = verticalOrderTraversal(root); // taking the answer vector from verticalOrderTraversal
    for(int i=0;i<ans.size();i++){ // go in the vector and print
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