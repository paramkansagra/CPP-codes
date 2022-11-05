#include <iostream>
#include <unordered_map>
#include <set>

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

#include <bits/stdc++.h> 

void prepAdjList(unordered_map<int,set<int>> &adjList,vector<pair<int,int>> edges){
    for(auto i:edges){
        adjList[i.first].insert(i.second);
        adjList[i.second].insert(i.first);
    }
}

void bfs(unordered_map<int,set<int>> adjList,unordered_map<int,bool>& visited,vector<int>& ans, int node){
    queue<int> q;
    q.push(node);
    
    visited[node] = 1;
    
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        
//         store front node in ans
        ans.push_back(frontNode);
        
//         traverse all neighbours of front node
        for(auto i:adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;
    
    prepAdjList(adjList,edges);
//     traverse all elements of graph
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
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