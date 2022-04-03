#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int>& nums,vector<int> output,int index,vector<vector<int>>& ans){
    // base case
    if(index>=nums.size()){
        ans.push_back(output);
        return ;
    }

    // exclude
    solve(nums,output,index+1,ans);

    // include
    output.push_back(nums[index]);
    solve(nums,output,index+1,ans);
}

vector<vector<int>> subSets(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> output;
    int index=0;
    solve(nums,output,index,ans);

    return ans;
}

int main(){

    int n;
    cin>>n;

    vector<int> nums;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }

    vector<vector<int>> powerSet = subSets(nums);
    for(int i=0;i<powerSet.size();i++){
        for(int j=0;j<powerSet[i].size();j++){
            cout<<powerSet[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}