#include <bits/stdc++.h>

using namespace std;

void printArr(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }cout<<endl;
}

int main(){

    // creating a vector
    // syntax = vector<type> variable name
    vector<int> v;

    // other way of initializing the vector
    // vector<data type> name_of_vector(size,initial fill)
    vector<int> new_vector(3,1);
    cout<<"printing the new_vector"<<endl;
    printArr(new_vector);

    // intially size the of array is 0
    cout<<"size of vetor v is "<<v.capacity()<<endl;

    // adding elements to vector v
    // syntax variable_name.push_back(what to add)

    v.push_back(1);
    cout<<"capacity of vector"<<v.capacity()<<endl;
    v.push_back(2);
    cout<<"capacity of vector"<<v.capacity()<<endl;
    // vector size doubles
    v.push_back(3);
    cout<<"capacity of vector"<<v.capacity()<<endl;
    
    // size shows the number of elements present
    cout<<v.size()<<endl;

    // same as appending a element in python

    // printing the array
    printArr(v);

    // it also allow container functions

    cout<<"Element at front "<<v.front()<<endl;
    cout<<"Element at back "<<v.back()<<endl;

    // like python has pop function to remove the last element
    // cpp has pop_back() but it doesnt return any element

    v.pop_back();
    printArr(v);

    // we can also empty the vector using empty 
    // its size become 0 meaning all the elements are removed
    // but its capacity remains the same
    v.clear();
    cout<<"printing after clearing"<<endl;
    printArr(v);

    return 0;
}