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

// so bottom view of binary tree is done using inorder traversal
// we would be knowing the level as well as the position of the node in the number line and 
// we will see that there is only one passing for a position like -2 -1 0 1 2 and so on
// this can be done by creating a map and storing the values in the same

vector<int> bottomViewOfTree(Node* root){ // we are taking root into the tree
    vector<int> ans; // making a answer vector to return
    if(root == NULL){ // if the root is null then return the empty vector
        return ans;
    }

    map<int,int> bottomView; // make a map called bottomView that is storing the horizontalLevel and node data as the value
    queue<pair<Node*,int>> q; // making a queue as a pair with first element being the node and second element being the horizontal level present 

    q.push(make_pair(root,0)); // now we push the first element root and 0 as the horizontal level
    
    while(!q.empty()){ // now we will be doing normal inOrderTraversal
        pair<Node*,int> front = q.front(); // pull the front element from the queue
        q.pop(); // pop the first element cause we dont want infinite looping

        Node* frontElement = front.first; // now pull the frontNodeElement from the pair
        int horizontalDistance = front.second; // pull the horizontalDistance from the pair

        bottomView[horizontalDistance] = frontElement->data; // now push the data of the front element and the horizontalDistance into the map no matter if present or not

        if(frontElement->left != NULL){ // now push the left element in the queue if present
            q.push(make_pair(frontElement->left,horizontalDistance-1));
        }
        if(frontElement->right != NULL){ // now push the right element in the queue if present
            q.push(make_pair(frontElement->right,horizontalDistance+1));
        }
    }

    for(auto i:bottomView){ // now we will be going thru the map and we will be pulling the second element as it is the node data
        ans.push_back(i.second); // push it into the answer vector
    }

    return ans; // return the answer
}

void print(Node* root){ // bring the root node for the printing
    vector<int> ans = bottomViewOfTree(root); // pull the answer vector from the bottomxViewOfTree
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