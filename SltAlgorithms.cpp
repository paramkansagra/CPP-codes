#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> &v){
    for(auto i:v){
        cout<<i<<" ";
    }cout<<endl;
}

int main(){
    vector<int> v;

    // adding elements in the vector in a sorted format

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    // finding the elements in the vector using binary search
    
    cout<<"is 5 present in the vector ? "<<binary_search(v.begin(),v.end(),5)<<endl;
    cout<<"is 6 present in the vector ? "<<binary_search(v.begin(),v.end(),6)<<endl;
    cout<<"is 7 presnt in the vector ? "<<binary_search(v.begin(),v.end(),7)<<endl;

    // now we need to find the iterator of the element so we can traverser from there

    // finding the lowerbound for elements
    
    cout<<"the lower bound is "<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;
    cout<<"the upper bound is "<<upper_bound(v.begin(),v.end(),6)-v.begin()<<endl;

    // lower and upper bound is nothing but the index of element from the 
    // left side and from the right side of the vector

    // we can find the max and min if we want

    int a = 3;
    int b = 5;

    cout<<"max of a and b is "<<max(a,b)<<endl;
    cout<<"min of a and b is "<<min(a,b)<<endl;

    // we can swap the variables if we want
    // works for all the containers
    swap(a,b);
    cout<<"value of a is "<<a<<endl;
    cout<<"value of b is "<<b<<endl;

    // we can reverse the string if we want

    string lol = "hello there this is param kansagra";
    reverse(lol.begin(),lol.end());
    cout<<lol<<endl;

    // we can rotate a vector or an array if we want
    // syntax rotate(vector start,how much rotate,v end);
    rotate(v.begin(),v.begin()+1,v.end());
    printVector(v);

    // sorting a vector
    // working on intro sort(heap sort insersion sort and quick sort)
    sort(v.begin(),v.end());
    printVector(v);

    return 0;
}