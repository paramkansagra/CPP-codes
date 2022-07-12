#include <iostream>

using namespace std;

class stack{
    private:
        int top,size; // making the private memebers for the top element size and array 
        int* arr;

    public:
        stack(int size){ // made a constructor where input of stack size is given
            this->size = size; 
            arr = new int[size];
            top = -1;
        }

        void push(int data){ // pushing elements into the stack
            if(top+1<size){ // condition for checking if any space is left in the stack
                arr[++top] = data; // increase the top by 1 and push the element into the array
            }
            else{
                cout<<"stack overflow"<<endl; // if there is no place left then print the stack is in overflow condition
            }
        }

        void pop(){
            if(top>=0){ // if there are any elements present in the stack then make the previous top = -1 and decrease the top
                arr[top--] = -1;
            }
            else{
                cout<<"stack underflow"<<endl; // if the stack is empty then stack underflow condition
            }
        }

        int peek(){
            if(top>=0 && top<size){ // printing the top most element of the stack
                return arr[top]; // returning the top element
            }
            else{
                cout<<"stack is empty"<<endl; // else print stack is empty and return -1
                return -1;
            }
        }

        bool isEmpty(){ // is the stack empty or what
            if(top<0){  // if top is less than 0 then stack is empty
                return true;
            }
            else{
                return false; // else it is not and return false
            }
        }

        int length(){ // return the length or the amount the stack is filled
            return top+1;
        }
};

int main(){

    stack st(5);

    st.push(10);
    cout<<st.peek()<<" ";
    st.push(55);
    cout<<st.peek()<<endl;

    st.pop();
    cout<<st.peek()<<endl;

    st.pop();

    if(st.isEmpty()){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }

    return 0;
} 