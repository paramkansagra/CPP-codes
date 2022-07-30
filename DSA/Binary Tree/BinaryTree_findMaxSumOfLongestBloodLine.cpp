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

void solve(Node* root,pair<int,int> curr,pair<int,int> &maxx){
    if(root == NULL){ // base case if the root node is null
        if(curr.first>maxx.first){ // check if the currLevel is greater than maxxLevel
            maxx.first = curr.first; // if yes then update the maxxLevel and maxxSum
            maxx.second = curr.second;
        }
        else if(curr.first == maxx.first){ // if currLevel and maxxLevel are equal then update maxxSum
            maxx.second = max(maxx.second,curr.second);
        }

        return ;
    }

    curr.second += root->data; // if it is not a leaf Node then increase the currSum with the root value
    curr.first++; // and update the currPair's level by 1

    solve(root->left,curr,maxx); // go in the left sub tree
    solve(root->right,curr,maxx); // go in the right sub tree
}

// so we have to go to the maximum tree length and find the sum of the same
// we will do this using inOrderTraversal with maintaing 2 pairs
// first pair is curr containing the current level and current sum
// second pair is the maxx pair containing the maxx level and maxxSum corrosponding to the maxLevel
// so we have to just go to each and every node if the node is NULL then update the maxx pair
// else go in the left side and go in the right side and do the same

int getLongestBloodLine(Node* root){ 
    pair<int,int> curr = make_pair(0,0); // making a pair with first as level and second as the sum
    pair<int,int> maxx = make_pair(0,0);

    solve(root,curr,maxx); // going in the solve function passing curr by value and maxx by refrence

    return maxx.second;
}

int main(){

    Node* root = NULL;

    // creating a tree
    root = buildTree(root);

    int ans = getLongestBloodLine(root);

    cout<<ans<<endl;

    return 0;
}