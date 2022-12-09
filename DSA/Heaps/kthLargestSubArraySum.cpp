#include <bits/stdc++.h>

using namespace std;

int main(){

    // first input the number of elements in the sub array and k
    int n,k;
    cin>>n>>k;

    // make a vector and take input in it
    vector<int> arr(n,-1);

    // take the input of the elements
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // make a max heap to store the elements
    priority_queue<int , vector<int> , greater <int> > pq;

    // now find the sub array sum and push in the pq
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j = i ; j < n ; j++){
            sum += arr[j];

            if(pq.size() < k){ // if the size of pq is less than k then just push into the priority queue
                pq.push(sum);
            }
            else{
                if(pq.top() < sum){ // else we will check if the top is smaller than the sum the pop the top and push the sum
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }

    cout<<pq.top()<<endl;

    return 0;
}