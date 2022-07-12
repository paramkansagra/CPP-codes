#include <iostream>
#include <stack>

using namespace std;

bool findRedundunt(string s){
    stack<char> st;

    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            st.push(ch);
        }
        else{
            if(ch == ')'){
                if(st.top() == '(') return true;
                else{
                    while(st.top() != '('){
                        st.pop();
                    }
                    st.pop();
                }
            }
        }
    }

    if(st.size() != 0){
        return true;
    }
    return false;
}

int main(){

    string s;
    cin>>s;

    if(findRedundunt(s)){
        cout<<"redundunt brackets found"<<endl;
    }
    else{
        cout<<"redundunt brackets not found"<<endl;
    }

    return 0;
}