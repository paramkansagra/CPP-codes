#include <bits/stdc++.h>

using namespace std;

int findMinCost(vector<int> ropes,int n){
    // to find the min cost 
    // make a min heap using priority queue
    // then just keep pulling out 2 min elements 
    // then do the sum and push it back until the length is equal to 1

    priority_queue<int , vector<int> , greater<int> > pq;

    for(int i=0;i<n;i++){
        pq.push(ropes[i]);
    }

    int sum = 0;
    while(pq.size() > 1){
        int min1 = pq.top();
        pq.pop();

        int min2 = pq.top();
        pq.pop();

        sum += min1 + min2; // find the sum

        pq.push(min1+min2); // push the resulting rope in the pq again
    }

    return sum; // return the final Min value of the rope 
}

int main(){

    // first ask the number of ropes
    int n;
    cin>>n;

    // make a vector to store all the ropes inside it
    vector<int> ropes(n,-1);
    for(int i=0;i<n;i++){
        cin>>ropes[i];
    }

    // now call the function and pass the vectors
    int minCost = findMinCost(ropes,n);

    cout<<minCost<<endl;

    return 0;
}