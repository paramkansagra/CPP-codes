#include <bits/stdc++.h>

using namespace std;

void inputPairs(vector<pair<int,int>>& pairs,int n){
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;

        pairs.push_back(make_pair(u,v));
    }
}

void makeAdjList(unordered_map<int,set<int>>& adjList,vector<pair<int,int>> pairs){
    for(auto i:pairs){
        int u = i.first;
        int v = i.second;

        adjList[u].insert(v);
    }
}

bool isCyclic(unordered_map<int,set<int>> adjList,unordered_map<int,bool>& visited,unordered_map<int,bool> dfsCall,int vertex){
    visited[vertex] = true;
    dfsCall[vertex] = true;

    for(auto i:adjList[vertex]){
        if(!visited[i]){
            if(isCyclic(adjList,visited,dfsCall,i)){
                return true;
            }
        }
        else if(dfsCall[i] == true){
            return true;
        }
    }
    
    return false;
}

int main(){

    int n;
    cin>>n;

    vector<pair<int,int>> pairs;
    inputPairs(pairs,n);

    unordered_map<int,set<int>> adjList;
    makeAdjList(adjList,pairs);

    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsCall;

    bool ans = false;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(isCyclic(adjList,visited,dfsCall,i)){
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