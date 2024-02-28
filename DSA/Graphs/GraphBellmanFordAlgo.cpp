#include <bits/stdc++.h>

using namespace std;

void bellman_ford(int source , int n , int m , vector<int>& distance , vector<vector<int>>& edges){
    distance[source] = 0;

    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < m ; j++){
            int src = edges[j][0];
            int dest = edges[j][1];
            int weight = edges[j][2];

            if(distance[src] != 1e9 && distance[src] + weight < distance[dest]){
                distance[dest] = distance[src] + weight;
            }
        }
    }

    // check for negetive cycle
    bool flag = 0;
    for(int j = 0 ; j < m ; j++){
        int src = edges[j][0];
        int dest = edges[j][1];
        int weight = edges[j][2];

        if(distance[src] != 1e9 && distance[src] + weight < distance[dest]){
            flag = 1;
        }
    }
}

int main(){

    cout<<"Input the number of nodes and the number of edges ";

    int n , m;
    cin>>n>>m;

    vector<vector<int>> adj_list(m);

    for(int i=0;i<m;i++){
        cout<<"Input source destination and weight ";
        int source , destination , weight;
        cin>>source>>destination>>weight;
        adj_list[i] = {source , destination , weight};
    }

    int source;
    cout<<"Input source ";
    cin>>source;

    vector<int> final_matrix(n + 1 , 1e9);
    bellman_ford(source , n , m , final_matrix , adj_list);

    for(auto i:final_matrix){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}