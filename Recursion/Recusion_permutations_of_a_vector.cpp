#include <iostream>
#include <vector>

using namespace std;

void solve(vector<int> nums,vector<vector<int>>&ans,int index){
    if(index>=nums.size()){
        ans.push_back(nums);
        return ;
    }

    for(int i=index;i<nums.size();i++){
        swap(nums[i],nums[index]);
        solve(nums,ans,index+1);
        swap(nums[i],nums[index]);
    }
}

vector<vector<int>> generatePermutations(vector<int> nums){

    vector<vector<int>> ans;
    int index = 0;
    solve(nums,ans,index);

    return ans;

}

int main(){

    int n;
    cin>>n;

    vector<int> s;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        s.push_back(temp);
    }

    vector<vector<int>> ans = generatePermutations(s);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }cout<<endl;

    return 0;
}