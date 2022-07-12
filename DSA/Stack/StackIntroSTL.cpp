#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<int> s; // creation of a stack

    s.push(2); // pushing 2 into the stack
    s.push(3); // pushing 3 into the stack

    cout<<"the size of the stack is "<<s.size()<<endl; // printing the size of the stack 

    cout<<s.top()<<endl; // top element to be printed i.e. 3
    s.pop(); // popping the top most element in the stack i.e. 3
    cout<<s.top()<<endl; // priting the top element i.e. 2

    if(s.empty()){ // just checking if the stack is empty or not
        cout<<"the stack is empty"<<endl;
    }
    else{
        cout<<"the stack is not empty and the top element is "<<s.top()<<endl; // if the stack is not empty then print the top element
    }

    return 0;
}