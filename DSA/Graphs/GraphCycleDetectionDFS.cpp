#include <bits/stdc++.h>

using namespace std;

void makeAdjList(vector<pair<int,int>> pairs,unordered_map<int,set<int>>& adjList){
    for(auto i:pairs){
        int u = i.first;
        int v = i.second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

bool isCyclicDFS(unordered_map<int,set<int>> adjList,unordered_map<int,bool>& visited,int vertex,int parent){
    visited[vertex] = true;

    for(auto i:adjList[vertex]){
        if(!visited[i]){
            bool cycleDetected = isCyclicDFS(adjList,visited,i,vertex);
            if(cycleDetected) return true;
        }
        else if(i != parent){
            return true;
        }
    }

    return false;
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
    makeAdjList(pairs,adjList);

    unordered_map<int,bool> visited;

    bool ans = false;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(isCyclicDFS(adjList,visited,i,-1)){
                ans = true;
                break;
            }
        }
    }

    if(ans){
        cout<<"Cycle is present";
    }
    else{
        cout<<"cycle is not present";
    }
    return 0;
}