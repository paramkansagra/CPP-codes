#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s){
    stack<char> st;

    for(int i=0;i<s.length();i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }
        else{
            if(s[i] == ')'){
                if(st.empty()) return false;
                if(st.top() != '(') return false;
                st.pop();
            }
            if(s[i] == ']'){
                if(st.empty()) return false;
                if(st.top() != '[') return false;
                st.pop();
            }
            if(s[i] == '}'){
                if(st.empty()) return false;
                if(st.top() != '}') return false;
                st.pop();
            }
        }
    }

    if(st.empty()) return false;
    return true;
}

int main(){

    string parenthese;
    cin>>parenthese;

    if(isValid(parenthese)){
        cout<<"balanced"<<endl;
    }
    else{
        cout<<"not balanced"<<endl;
    }

    return 0;
}