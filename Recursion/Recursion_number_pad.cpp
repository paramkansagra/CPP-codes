#include <iostream>
#include <vector>

using namespace std;

void solve(string s,string output,int index,string mapping[],vector<string>& ans){
    if(index>=s.length()){
        ans.push_back(output);
        return ;
    }

    int number = s[index]-'0';
    string value = mapping[number];

    for(int i=0;i<value.length();i++){
        solve(s,output+value[i],index+1,mapping,ans);
    }
}

vector<string> letterCombinations(string s){
    vector<string> ans;
    string output="";

    if(s.length() == 0){
        return ans;
    }

    int index = 0;
    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    solve(s,output,index,mapping,ans);
}

int main(){

    string s;
    cin>>s;

    vector<string> ans = letterCombinations(s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }cout<<endl;

    return 0;
}