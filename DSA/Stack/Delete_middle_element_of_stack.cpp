#include <iostream>
#include <stack>

using namespace std;

void deleteMiddleElement(stack<int>&inputStack){
    int size = inputStack.size();
    int index = 0;

    stack<int> newStack;

    if(size%2 != 0) size = (size-1)/2;
    else size = size/2;

    while(index != size){
        newStack.push(inputStack.top());
        inputStack.pop();
        index++;
    }

    inputStack.pop();

    while(newStack.empty() != true){
        inputStack.push(newStack.top());
        newStack.pop();
    }
}

int main(){

    stack<int> inputStack;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        inputStack.push(temp);
    }

    deleteMiddleElement(inputStack);

    for(int i=0;i<inputStack.size();i++){
        cout<<inputStack.top()<<" ";
        inputStack.pop();
    }

    return 0;
}