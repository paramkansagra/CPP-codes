#include <iostream>
#include <unordered_map>
#include <list>

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



int main(){

    int n;
    cout<<"Input the number of nodes"<<endl;
    cin>>n;

    int m;
    cout<<"Input the number of edges"<<endl; 
    cin>>m;s

    graph<int> g; // create a undirected graph

    for(int i=0;i<m;i++){
        int u,v; // konsa node se konse node pe jaa raha hai
        cin>>u>>v;

        g.addEdge(u,v,0); 
    }

    return 0;
}