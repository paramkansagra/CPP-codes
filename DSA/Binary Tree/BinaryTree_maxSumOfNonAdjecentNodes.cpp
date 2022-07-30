#include <iostream>
#include <queue>

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

pair<int,int> solve(Node* root){
    pair<int,int> ans = make_pair(0,0);
    if(root == NULL){ // initial condition  that if the root is null
        return ans; // return the empty answer pair
    }

    pair<int,int> left = solve(root->left); // else get the left side ka pair
    pair<int,int> right = solve(root->right); // and get the right side ka pair

    ans.first = root->data + left.second + right.second; // the first one in which we are including the node so node->data + left.second + right.second meaning add to the non included ones
    ans.second = max(left.first,left.second) + max(right.first,right.second); // when we are not including then we have to just sum the max of the first and second values of the pairs and add

    return ans; // return the answer pair
}

// so we have been given a tree
// and we have to find the max sum of the non adjecent nodes 
// so when we go on each node we have 2 options we can either include it or exclude it from the sum
int maxSumOfNonAdjecentNodes(Node* root){
    pair<int,int> ans = solve(root); // so we will get the answer in form of a pair
    return max(ans.first,ans.second); // the first one will be the one including it and the second one will be excuding it
    // and we return the max of the both
}

int main(){

    Node* root = NULL;

    // creating a tree
    root = buildTree(root);

    int ans = maxSumOfNonAdjecentNodes(root);

    cout<<ans<<endl;

    return 0;
}