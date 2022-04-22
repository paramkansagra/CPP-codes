#include <bits/stdc++.h>

using namespace std;

// set data structrue only keeps 1 copy of a element
// i.e. there cant be multiple copies of a element

// how is it implemented ? using BST or binary search tree
// we can only add or delete a elemnt we cant modify the element

// elements are returned in a sorted order
// there is unordered set too where it is faster than set
// and the elements are returned in a unorder or unsorted manner

void printSet(set<int> s){
    for(auto i:s){
        cout<<i<<" ";
    }cout<<endl;
}

int main(){

    set<int> s;
    
    // pushing elements into set using insert method
    // time complexity of inserting the element is O(log n  )
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);

    // printing the set
    printSet(s);

    // we can see the set is printed in a sorted order
    // and 1 element can only exist once

    // we can also find the elemnts in a set
    // it returns the iterator of the element

    cout<<*s.find(1)<<endl;

    // we can also erase the set using erase function
    // it takes a iterator and removes it
    s.erase(s.begin()); // removing the first element
    printSet(s);

    auto it = s.begin();
    it++;
    s.erase(it);
    printSet(s);

    // we can use the count function to see if the element
    // is present or not

    cout<<"is 5 present in the set"<<s.count(5)<<endl;
    cout<<"is 2 present in the set"<<s.count(2)<<endl;

    // adding elements for fun

    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(8);


    // using the find function we can get the iterator
    // of the element if it is present in the set
    set<int>::iterator itr = s.find(2);

    // the *itr prints the value at that iterator
    cout<<"value at iterator"<<*itr<<endl;

    printSet(s);

    return 0;
}