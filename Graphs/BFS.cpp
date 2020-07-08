// Author : Harshit Sharma
// BFS implementation

#include<iostream>
#include<vector>
#include<queue>
#define ll long long int
using namespace std;

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

    queue<ll> Queue;
    Queue.push(1);
    while(!Queue.empty()){
        ll node = Queue.front();
        Queue.pop();
        visited[node] = true;
        cout<<node<<" ";
        for(i=0;i<graph[node].size();++i){
            if(!visited[graph[node][i]]){
                Queue.push(graph[node][i]);
                visited[graph[node][i]] = true;
            }
        }
    }

    cout<<endl;
}