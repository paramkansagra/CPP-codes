#include <iostream>
#include <stack>

using namespace std;

class queue{
    private:
        stack<int> st;

    public:
        void push(int data){
            stack<int> temp;
            while(!st.empty()){
                temp.push(st.top());
                st.pop();
            }
            st.push(data);
            while(!temp.empty()){
                st.push(temp.top());
                temp.pop();
            }
        }

        int front(){
            return st.top();
        }

        int pop(){
            int data = st.top();
            st.pop();
            return data;
        }

        int back(){
            stack<int> temp;
            while(!st.empty()){
                temp.push(st.top());
                st.pop();
            }

            int data = temp.top();

            while(!temp.empty()){
                st.push(temp.top());
                temp.pop();
            }

            return data;
        }
};

int main(){

    return 0;
}