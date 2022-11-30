#include <bits/stdc++.h>

using namespace std;

map<int,set<int>> dijkstra(int source,vector<vector<int>> adjList,int n){
    map<int,set<int>> ans;
    map<int,bool> visited;

    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    visited[source] = true;
    
    int count = 0;
    
    while(true){
        int parent = -1;
        int node = -1;
        int minDistance = INT_MAX;

        for(int i=0;i<n;i++){
            if(visited[i] == true){
                for(int j=0;j<n;j++){
                    if(adjList[i][j] != 0 && adjList[i][j] <= minDistance && visited[j] == false){
                        minDistance = adjList[i][j];
                        parent = i;
                        node = j;
                    }
                }
            }
        }

        int k = 0;
        for(int i=0;i<n;i++){
            if(visited[i]) k++;
        }

        if(k == n){
            break;
        }
        

        if(parent != -1){
            visited[node] = true;
            ans[parent].insert(node);
            ans[node].insert(parent);
            count += minDistance;
        }
    }

    cout<<count<<endl;
    return ans;
}

int main(){

    int n;
    cin>>n;

    vector<vector<int>> adjList;
    for(int i=0;i<n;i++){
        vector<int> l;
        for(int j=0;j<n;j++){
            int temp;
            cin>>temp;
            l.push_back(temp);
        }
        adjList.push_back(l);
    }

    int source;
    cin>>source;

    map<int,set<int>> ans;
    ans = dijkstra(source,adjList,n);

    for(auto i:ans){
        cout<<i.first<<" ";
        for(auto j:i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}