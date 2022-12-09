#include <bits/stdc++.h>

using namespace std;


// make a new data structure to store the data row and column of the array
class Node{
    public:
        int data; 
        int row;
        int col;

        // make a constructor to take the values in the node
        Node(int data,int row,int cl){
            this->data = data;
            this->row = row;
            this->col = col;
        }
};

// make a new class to compare the nodes and return the values
class compare{
    public:
        bool operator()(Node* a,Node* b){
            return a->data > b->data;
        }
};

vector<int> mergeKSortedArrays(vector<vector<int>> arr,int n){

    vector<int> ans; // make a answer array to push the elements into

    // make a min heap to store the minimum element from the arrays
    priority_queue<Node* , vector<Node*> , compare> minHeap;

    // push the first elements of all the arrays
    for(int i=0;i<n;i++){
        Node* newNode = new Node(arr[i][0],i,0); // push the first elements also the row and col in the constructor
        minHeap.push(newNode); // push the node in the min heap
    }

    // while the min heap has elements we have to pull out the minimum element from the heap and then push in the array
    while(minHeap.size() > 0){
        Node* top = minHeap.top(); // first pull out the top element from the heap
        minHeap.pop(); // pop that element from the heap

        // push the top element into the answer array
        ans.push_back(top->data);

        int row = top->row;
        int col = top->col;

        if(col+1 < arr[row].size()){
            Node* newNode = new Node(arr[row][col+1],row,col+1);
            minHeap.push(newNode);
        }
    }

    return ans;
}

int main(){

    // input the number of rows
    int n;
    cin>>n;

    // make a 2d vector to save the arrays
    vector<vector<int>> arr;

    for(int i=0;i<n;i++){
        // input k the number of col in the array
        int k;
        cin>>k;

        // take the input of the array in the array
        vector<int> vect(k,-1);
        for(int i=0;i<k;i++){
            cin>>vect[i];
        }

        arr.push_back(vect); // push the temporary array to the final array
    }

    vector<int> ans = mergeKSortedArrays(arr,n); // get the answer from the function

    for(auto i:ans){ // print the final merged sorted array
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}