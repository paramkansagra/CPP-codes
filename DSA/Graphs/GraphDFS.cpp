#include <bits/stdc++.h>

using namespace std;

template <class T>
class graph{
    public:
        unordered_map<T,list<T>> adj;

        // direction is for if the graph is directed or not
        // int u is the node and v is the new node we are adding
        void addEdge(T u,T v,bool direction){
            // direction == 0 means undirected graph
            // direction == 1 means directed graph

            // create a edge from u to v
            adj[u].push_back(v);

            // if the graph is undirected then add adj[v] to u
            if(direction == 0){
                adj[v].push_back(u);
            }
        }
};


void dfs(int node,unordered_map<int,bool>& visited,unordered_map<int,list<int>>& adjList,vector<int>& component){
    component.push_back(node);
    visited[node] = true;
    
//     har connected node ke liye recursive call
    for(auto i:adjList[node]){
        if(!visited[i]){
            dfs(i,visited,adjList,component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int,list<int>> adjList;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    vector<vector<int>> ans;
    unordered_map<int,bool> visited;
    
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,visited,adjList,component);
            ans.push_back(component);
        }
    }
    
    return ans;
}

int main(){

    int n;
    cout<<"Input the number of nodes"<<endl;
    cin>>n;

    int m;
    cout<<"Input the number of edges"<<endl; 
    cin>>m;

    graph<int> g; // create a undirected graph

    for(int i=0;i<m;i++){
        int u,v; // konsa node se konse node pe jaa raha hai
        cin>>u>>v;

        g.addEdge(u,v,0); 
    }

    return 0;
}