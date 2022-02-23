#include <bits/stdc++.h>

using namespace std;

void printDeque(deque<int> &d){
    for(int i=0;i<d.size();i++){
        cout<<d[i]<<" ";
    }cout<<endl;
}

int main(){

    // syntax of making a deque
    // deque<data type> name_of_variable;

    deque<int> d;

    // the good thing of deque is we can add elements from 
    // front and the back
    // syntax var.push_back(data) and var.push_front(data)

    d.push_back(1);
    d.push_front(3);

    printDeque(d);

    // we can also remove elements from the back and the
    // front using var.pop_back() and var.pop_front()
    d.push_back(10);
    d.push_back(14);

    printDeque(d);

    d.pop_back();
    printDeque(d);
    d.pop_front();
    printDeque(d);

    // we can access the elements randomly using d[pos]
    // we can also use d.at(pos)

    cout<<d.at(1)<<endl;

    // as in vector we can also see if the deque is empty
    // or not using var.empty()
    // it returns a bool variable

    cout<<"is the deque empty "<<d.empty()<<endl;

    // as we can use the erase function in an vector
    // we also have erase function in deque
    cout<<"printing the deque before";
    printDeque(d);

    // syntax
    // var.erase(start,end) as we do in python

    d.erase(d.begin(),d.begin()+1);

    cout<<"print the deque after"<<endl;
    printDeque(d);
    cout<<"deque size"<<d.size()<<endl;
    cout<<"deque assigned size"<<d.max_size()<<endl;
    
    return 0;
}