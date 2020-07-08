// Author : Harshit Sharma
// Depth First Search algorithm

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<stack>
#define ll long long int
using namespace std;

int main(){

    ll nodes,edges,i,j,u,v;
    cin>>nodes>>edges;

    // Basic Structure of graph
    vector<ll> graph[nodes+1];
    for(i=0;i<edges;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // In case of undirected graph
    }
    stack<ll> Stack;
    bool visited[nodes+1];
    memset(visited,false,sizeof(visited));
    Stack.push(1);
    while(!Stack.empty()){
        ll node = Stack.top();
        visited[node] = true;
        cout<<node<<" ";
        Stack.pop();

        for(i=0;i<graph[node].size();++i){
            if(!visited[graph[node][i]]){
                Stack.push(graph[node][i]);
                visited[graph[node][i]] = true;
            }
        }
    }
    cout<<endl;

}