#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<int> s; // creation of a stack

    s.push(2); // pushing 2 into the stack
    s.push(3); // pushing 3 into the stack

    cout<<s.top()<<endl; // top element to be printed i.e. 3
    s.pop(); // popping the top most element in the stack i.e. 3
    cout<<s.top()<<endl; // priting the top element i.e. 2

    return 0;
}