#include <bits/stdc++.h>

using namespace std;

int main(){

    // defining a stack
    // syntax stack<data type> var_name;
    stack<string> s;
    
    // pushing element into the stack
    s.push("param");
    s.push("kansagra");
    s.push("c++");

    // prints the top element of the stack
    cout<<s.top()<<endl;

    // popping out the top element
    s.pop();

    cout<<s.top()<<endl;

    // printing the size of the stack
    cout<<"size of stack is "<<s.size()<<endl;

    // printing if the stack is empty or not
    cout<<"the stack is empty "<<s.empty()<<endl;

    return 0;
}