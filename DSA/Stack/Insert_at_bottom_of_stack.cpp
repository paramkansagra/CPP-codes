#include <iostream>
#include <stack>

using namespace std;

stack<int> insertAtBottom(stack<int> myStack,int x){
    if(myStack.empty()){
        myStack.push(x);
        return myStack;
    }

    int top = myStack.top();
    myStack.pop();
    myStack = insertAtBottom(myStack,x);
    myStack.push(x);

    return myStack;
}

void print(stack<int> st){
    if(st.empty()){
        return ;
    }
    cout<<st.top()<<" ";
    st.pop();
    print(st);
}

int main(){

    stack<int> st;
    int x,n;

    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        st.push(temp);
    }

    cin>>x;

    st = insertAtBottom(st,x);
    print(st);

    return 0;
}