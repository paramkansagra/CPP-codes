#include <iostream>
#include <stack>

using namespace std;

void insertInSorted(stack<int>& st,int ele){
    if(st.empty()){
        st.push(ele);
        return ;
    }
    if(st.top()<ele){
        st.push(ele);
    }
    else{
        int top = st.top();
        st.pop();
        insertInSorted(st,ele);
        st.push(top);
    }
}

void sort(stack<int>& st){
    if(st.empty()){
        return ;
    }
    int top = st.top();
    st.pop();
    sort(st);

    insertInSorted(st,top);
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
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        st.push(temp);
    }

    sort(st);
    print(st);

    return 0;
}