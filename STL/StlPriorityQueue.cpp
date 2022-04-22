#include <bits/stdc++.h>

using namespace std;

// in a priority queue the max element is always present
// at the first

int main(){
    
    // when we initialize this then it becomes a max heap
    // type queue like when we fetch data from it then 
    // data we pull will always be the max

    priority_queue<int> maxi;

    // min heap
    priority_queue<int,vector<int>,greater<int>> mini;

    // pushing data into the max heap

    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);

    // pushing data in min heap

    mini.push(1);
    mini.push(3);
    mini.push(2);
    mini.push(0);

    // printing the data
    int n = maxi.size();
    for(int i=0;i<n;i++){

        // we are printing the top element and then popping 
        // it out to get the next element

        cout<<maxi.top()<<" ";
        maxi.pop();
    }cout<<endl;

    // in the printing of maxi we can see the max element
    // is removed in the starting 

    // lets print the min heap or mini

    n = mini.size();
    for(int i=0;i<n;i++){
        cout<<mini.top()<<" ";
        mini.pop();
    }cout<<endl;

    cout<<"is max heap empty ? "<<maxi.empty()<<endl;
    cout<<"is min heap empty ? "<<mini.empty()<<endl;
    
    return 0;
}