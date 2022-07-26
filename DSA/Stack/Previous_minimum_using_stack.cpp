#include <iostream>
#include <vector>

using namespace std;

vector<int> prevMinimum(vector<int> st,int n){
    vector<int> ans(n);
    
}

int main(){

    vector<int> st;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        st.push_back(temp);
    }

    vector<int> prev = prevMinimum(st,n);
    for(int i=0;i<prev.size();i++){
        cout<<prev[i]<<" ";
    }cout<<endl;

    return 0;
}