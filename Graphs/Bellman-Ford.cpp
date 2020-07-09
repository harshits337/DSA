// Author : Harshit Sharma
// Bellman Ford Algorithm Implementation

#include<iostream>
#include<vector>
#include<utility>
#define ll long long int
using namespace std;

int main(){
    ll nodes,edges,i,j,u,v,wt,k;
    cin>>nodes>>edges;
    vector<pair<ll, ll> > graph[nodes+1];

    for(i=0;i<edges;i++){
        cin>>u>>v>>wt;
        graph[u].push_back(make_pair(v,wt));
    }

    ll distance[nodes+1];
    memset(distance,10000,sizeof(distance));
    distance[1] = 0;

    for(k=0;k<nodes-1;k++){
        for(i=1;i<=nodes;i++){
            for(j=0;j<graph[i].size();j++){
                if(distance[i] + graph[i][j].second < distance[graph[i][j].first]){
                    distance[graph[i][j].first] = distance[i] + graph[i][j].second; 
                }
            }
        }
    }
    bool check = false;
    for(i=1;i<=nodes;i++){
        for(j=0;j<graph[i].size();j++){
            if(distance[i] + graph[i][j].second < distance[graph[i][j].first]){
                check = true;
            }
        }
    }
    if(check){
        cout<<"The graph has negative weight cycle"<<endl;
    }
    else {
        for(i=1;i<=nodes;i++){
            cout<<1<<"-->"<<distance[i]<<endl;
        }
    }
}

// Test Case : with no negative weight cycle
// 5 8
// 1 2 -1
// 1 3 4
// 2 3 3
// 2 4 2
// 4 2 1
// 4 3 5
// 2 5 2
// 5 4 -3

// With negative weight cycle 
// 4 5
// 2 1 4
// 2 3 -3
// 3 4 2
// 4 2 -1
// 1 3 -2

