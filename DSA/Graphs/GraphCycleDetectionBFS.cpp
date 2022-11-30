#include <bits/stdc++.h>

using namespace std;

bool isCyclicBFS(int source,unordered_map<int,bool>& visited,unordered_map<int,set<int>> adjList,unordered_map<int,int>& parent){
    visited[source] = 1;
    parent[source] = -1;

    queue<int> q;
    q.push(source);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i:adjList[front]){
            if(visited[i] == true && i != parent[i]){
                return true;
            }
            else if(!visited[i]){
                q.push(i);
                visited[i] = true;
                parent[i] = front;
            }
        }
    }

    return false;
}

void makeAdjList(unordered_map<int,set<int>>& adjList,vector<pair<int,int>> pairs){
    for(auto i:pairs){
        int u = i.first;
        int v = i.second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

int main(){

    int n;
    cin>>n;

    vector<pair<int,int>> pairs;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;

        pairs.push_back(make_pair(u,v));
    }

    unordered_map<int,set<int>> adjList;
    makeAdjList(adjList,pairs);

    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;

    bool ans = false;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(isCyclicBFS(i,visited,adjList,parent)){
                ans = 1;
                break;
            }
        }
    }

    if(ans){
        cout<<"Cycle is present";
    }
    else{
        cout<<"Cycle is not present";
    }

    return 0;
}