// Author : Harshit Sharma
//  Dijkstra's Algorithm for single source shortest path

#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#define ll long long int
using namespace std;

int main(){
    ll nodes,edges,i,j,u,v,wt;
    cin>>nodes>>edges;
    vector<pair<ll, ll> > graph[nodes+1];
    for(i=0;i<edges;++i){
        cin>>u>>v>>wt;
        graph[u].push_back(make_pair(v,wt));
        // graph[v].push_back(make_pair(u,wt)); //Only in case of undirected Graph
    }
    
    ll distance[nodes+1];
    memset(distance,10000,sizeof(distance));
    distance[1] = 0; // Source Node

    priority_queue<pair<ll,ll> > minHeap;
    minHeap.push(make_pair(distance[1],1));
    while(!minHeap.empty()){
        pair<ll,ll> top = minHeap.top();
        ll dist = top.first;
        ll node = top.second;
        minHeap.pop();
        for(i=0;i<graph[node].size();i++){
            if(dist + graph[node][i].second < distance[graph[node][i].first]){
                distance[graph[node][i].first] = dist + graph[node][i].second;
                minHeap.push(make_pair(distance[graph[node][i].first],graph[node][i].first));
            }
        }
    }

    for(i=1;i<=nodes;++i){
        cout<<1<<"-->"<<distance[i]<<endl;
    }
}