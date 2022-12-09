#include <bits/stdc++.h>

using namespace std;

int main(){

    // given n number of elements in the array we have to find the kth smallest element in the heap
    int n,k;
    cin>>n>>k;

    // first make an array and take input in it
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // now we have to find the kth smallest element

    // approch 1
        // to sort the array and then find the n-k th element and return it
        // time conplexity O(nlogn)
    
    // approch 2
        // to make a maxHeap using priority queue
        // the max stays at the top
        // if we get any element which is smaller than it then we remove the top from the heap
        // else we will pass the element

    priority_queue<int> pq;
    
    // first insert the k element in the pq
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    // now we will be checking each and element in the array
    for(int i=k;i<n;i++){
        int top = pq.top();
        if(top > arr[i]){ // if top is greater than the incoming element then we will pop out the elements
            pq.pop(); // pop out the top element
            pq.push(arr[i]); // push in the incoming element
        }
    }

    int top = pq.top();
    cout<<top<<endl;

    return 0;
}