#include <iostream>
#include <vector>

using namespace std;

void solve(string str,int index,vector<string>& ans,string output){
    if(index>=str.length()){
        if(output != ""){
            ans.push_back(output);
        }
        return ;
    }

    // exclude
    solve(str,index+1,ans,output);

    // include
    output += str[index];
    solve(str,index+1,ans,output);
}

vector<string> subsequences(string str){
    vector<string> ans;
    string output = "";
    int index = 0;

    solve(str,index,ans,output);

    return ans;
}

int main(){

    string str;
    cin>>str;

    vector<string> ans = subsequences(str);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}