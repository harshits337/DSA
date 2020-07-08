// Author : Harshit Sharma
// Recursive implementation of DFS

#include<iostream>
#include<vector>
#define ll long long int
using namespace std;

void dfs(vector<ll> *graph,bool * visited,ll index){
    visited[index] = true;
    cout<<index<<" ";
    for(ll i=0;i<graph[index].size();i++){
        if(!visited[graph[index][i]]){
            dfs(graph,visited,graph[index][i]);
        }
    }
}

int main(){
    ll nodes,edges,i,j,u,v;
    cin>>nodes>>edges;
    vector<ll> graph[nodes+1];

    for(i=0;i<edges;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }    

    bool visited[nodes+1];
    memset(visited,false,sizeof(visited));

    for(i=1;i<=nodes;i++){
        if(!visited[i]){
            dfs(graph,visited,i);
        }
    }
    cout<<endl;
}