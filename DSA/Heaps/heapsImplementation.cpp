#include <bits/stdc++.h>

using namespace std;

class heap{
    public: 

        // making a array and a size variable
        int arr[100];
        int size = 0;

        heap(){ // make a constuctor to mark the 0th position as -1
            arr[0] = -1; // and size to be 0
            size = 0;
        }

        void insert(int val){ // first incease the size of the array by 1
            size += 1;
            int index = size;
            arr[index] = val; // and insert the element in the index

            // now we will compare
            // assuming it is a max heap
            // the child node should be smaller than the parent node
            // if the child node is greater than the parent node we will swap

            while(index > 1){ // while the index is greater than 1
                int parent  = index/2; // check for the parent
                if(arr[parent] < arr[index]){ // if the parent is smaller than the child
                    swap(arr[parent],arr[index]); // then swap the nodes
                    index = parent; // and change the index to parent to check the heap that is upper
                }
                else{
                    return ; // else if the condition is true just break out of the statement
                }
            }
        }

        void deleteNode(){
            // when we talk about deleting a node in a heap
            // we talk about deleting the root node of the heap

            // 1. jo node last me padi hai usko front me daalo
            // 2. remove the last node
            // 3. just make sure that the heap properties are still followed

            // propogate the root node to the correct position
            // see the child nodes and if they are greater then swap
            

            if(size == 0){
                cout<<"Nothing to delete"<<endl;
                return ;
            }

            // last node ko first node me daalo
            arr[1] = arr[size];
            size -= 1; // decrement the size by 1 to remove the last node

            int i = 1;
            while(i < size){
                int leftIndex = i*2;
                int rightIndex = i*2 + 1;

                if(leftIndex < size && arr[i] < arr[leftIndex]){
                    swap(arr[i],arr[leftIndex]);
                    i = leftIndex;
                }
                else if(rightIndex < size && arr[i] < arr[rightIndex]){
                    swap(arr[i],arr[rightIndex]);
                    i = rightIndex;
                }
                else{
                    return ;
                }
            }
        }

        void print(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }cout<<endl;
        }
};

// heapify me logic kya hai
// 1. we dont consider the leaf nodes cause vo apne aap heaps hai
// 2. go from root node to lower nodes
// check if the left or the right nodes have more value than it
// if yes then update the value of the indexes

// if we have updated the index then we will go to the lower nodes and check if it is accepting the
// condition of heap

// also the leaf nodes are present from n/2 to n
// do an example and you would know 

void heapify(int arr[],int n,int i){
    int largest = i; // first mark largest = i // cause the condition of heap is root node should be the largest
    int left = 2*i; // finding the left node
    int right = 2*i+1; // finding the right node

    if(left <= n && arr[largest] < arr[left]){ // if the left node is in the range and it is greater than the largest node
        largest = left; // then change the largest node
    }
    if(right <= n && arr[largest] < arr[right]){ // if the right node is in the range and it is greater than the largest node
        largest = right; // then change the largest node
    }

    if(largest != i){ // if the largest node is not equal to the input node
        swap(arr[largest],arr[i]); // means left or the right value is greater than the root value
        heapify(arr,n,largest); // so swap it and also go in the lower heaps to check if the heap condition is true or not
    }

    // if the largest node is the node that came in the input then we dont have to do anything
    // so we can return from the function
}

// heap sort (consider a max heap) (time complexity => O(nlogn))
// algo:-
// 1. swap the first and the last element
// 2. reduce the array size by 1
// 3. heapify the first element 
// do it till the size is > 1

void heapSort(int arr[],int n){
    int size = n;

    while(size > 1){
        // s1 swap
        swap(arr[size],arr[1]);

        // s2 decrease the size by 1
        size--;

        // s3 heapify
        heapify(arr,size,1);
    }

    // printing the array
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

int main(){

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;

    // starting from n/2 as the nodes from n/2 to n are leaf nodes
    for(int i=n/2;i>=0;i--){
        heapify(arr,n,i); // heapify the nodes 
    }

    // printing the heapified array
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    heapSort(arr,n);

    return 0;
}