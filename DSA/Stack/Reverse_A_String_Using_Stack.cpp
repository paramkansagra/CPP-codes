#include <iostream>
#include <stack>

using namespace std;

// we are taking advantage of the LIFO(last in first out) property of stack
// the last element that is pushed into the string is pulled the first out
// meaning the last element that has been pushed into the string is pulled out to be the first
// so last element pushed in will become first in the new string and we can reverse the string

string reverse(string s){

    stack<char> st; // make a stack using stl
    
    for(int i=0;i<s.length();i++){ // pushing the string elements one by one
        st.push(s[i]);
    }

    s = ""; // empty the string
    while(st.empty() != true){ // elements at the top of the stack remove it and push in the string
        s += st.top(); // this will make the string in a reversed manner cause last in first out
        st.pop();
    }

    return s; // return the new string
}

int main(){

    string s; // making a string s for input
    cin>>s; // take the input of the string

    s = reverse(s); // call the function and reassign s with the new string
    cout<<s<<endl; // print the string

    return 0;
}