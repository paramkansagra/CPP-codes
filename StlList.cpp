#include <bits/stdc++.h>

using namespace std;

// idhar the list is implemented using the double linked list concept

// we cant do random access operations like we used to do
// in vector and in deque and array

// so to access the element the time complexity is O(n)

void printList(list<int> &l){
    for(int i:l){ // similar implementation to // for i in list
        cout<<i<<" ";
    }cout<<endl;
}

int main(){

    list<int> l;

    // how to add elements to a list
    // we use the push_back function

    l.push_back(1);
    l.push_front(2);
    printList(l);

    // how to copy a list
    list<int> new_list(l);
    // the list got copied

    // we can also initialize the list
    // list<data type> variable_name(number_of_data,intial_element)
    list<int> data(5,100); // 5 times 100
    printList(data);

    // we also have list.begin() and list.end()
    // *pointer returns the value stored in it o(1)
    cout<<"first element "<<*l.begin()<<endl;
    cout<<"last element "<<*l.end()<<endl;

    // we can also check if the list is empty or not
    cout<<"is the list empty "<<l.empty()<<endl;

    // we also have erase in list o(n)
    // we can erase using erase function
    // jo bhi bracket me doge delete ho jayega
    l.erase(l.begin());
    cout<<"after erase"<<endl;
    printList(l);

    // we can also pop_back and pop_front
    l.push_back(10);
    l.push_back(12);
    l.push_back(14);
    l.push_back(16);
    printList(l);
    l.pop_front();
    printList(l);
    l.pop_back();
    printList(l);

    // size of list
    cout<<"size of list is "<<l.size()<<endl;

    return 0;
}