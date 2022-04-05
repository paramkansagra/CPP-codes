#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>> maze,vector<vector<int>> visited,int x,int y,int n){
    if((x>=0 && x<n) && (y>=0 && y<n) && maze[x][y] == 1 && visited[x][y] == 0){
        return true;
    }
    return false;
}

void solve(vector<vector<int>> maze,vector<string>& ans,vector<vector<int>> visited,int x,int y,int n,string output){
    if(x == n-1 && y == n-1){
        ans.push_back(output);
        return ;
    }

    visited[x][y] = 1;

    // down x+1
    if(isSafe(maze,visited,x+1,y,n)){
        output.push_back('D');
        solve(maze,ans,visited,x+1,y,n,output);
        output.pop_back();
    }
    // up x-1
    if(isSafe(maze,visited,x-1,y,n)){
        output.push_back('U');
        solve(maze,ans,visited,x-1,y,n,output);
        output.pop_back();
    }
    // left y-1
    if(isSafe(maze,visited,x,y-1,n)){
        output.push_back('L');
        solve(maze,ans,visited,x,y-1,n,output);
        output.pop_back();
    }
    //  right y+1
    if(isSafe(maze,visited,x,y+1,n)){
        output.push_back('R');
        solve(maze,ans,visited,x,y+1,n,output);
        output.pop_back();
    }

    visited[x][y] = 0;
}

vector<string> findPath(vector<vector<int>> maze,int n){
    vector<string> ans;
    if(maze[0][0] == 0){
        return ans;
    }

    int srcx = 0;
    int srcy = 0;
    string output = "";

    vector<vector<int>> visited = maze;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j] = 0;
        }
    }

    solve(maze,ans,visited,srcx,srcy,n,output);

    return ans;

}

int main(){

    int n,m;
    cin>>n;

    vector<vector<int>> maze;
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;

            temp.push_back(x);
        }
        maze.push_back(temp);
    }

    vector<string> ways = findPath(maze,n);

    for(int i=0;i<ways.size();i++){
        cout<<ways[i]<<" ";
    }cout<<endl;

    return 0;
}