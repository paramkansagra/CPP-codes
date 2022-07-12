#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int>& st,int ele){
    if(st.empty()){
        st.push(ele);
        return ;
    }

    int top = st.top();
    st.pop();
    insertAtBottom(st,ele);
    st.push(top);
}

void reverseStack(stack<int>& st){
    if(st.empty()){
        return ;
    }
    int top = st.top();
    st.pop();

    reverseStack(st);
    insertAtBottom(st,top);
}

void print(stack<int> st){
    int top = st.top();
    st.pop();

    cout<<top<<" ";
    print(st);
}

int main(){

    stack<int> st;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        st.push(temp);
    }

    print(st);
    reverseStack(st);
    print(st);

    return 0;
}