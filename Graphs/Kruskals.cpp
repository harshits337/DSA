// Author : Harshit Sharma
// Kruskal's algorithm for MST using disjoint set union by rank and path compression

#include<iostream>
#include<vector>
#include<utility>
#include<iterator>
#include<map>
#include<algorithm>
#define ll long long int
using namespace std;

class Node {
    public:
        ll index;
        ll rank;
};

class DisjointSet {
    public:
        map<ll,Node> mapper;
        ll parents[1000];
        void makeSet(ll index);
        ll findSet(ll index);
        bool unionSet(ll index1, ll index2);
};

void DisjointSet :: makeSet(ll index){
    Node node ;
    node.index = index;
    node.rank = 0;
    parents[index] = index;
    mapper.insert(make_pair(index,node));
}

ll DisjointSet :: findSet(ll index){

   if(parents[index] == index){
       return index;
   }

   return parents[index] = findSet(parents[index]);
}

bool DisjointSet :: unionSet(ll index1, ll index2){
   
   ll parentOfIndex1 = findSet(index1);
   ll parentOfIndex2 = findSet(index2);
   
   auto it = mapper.find(parentOfIndex1);
   Node node1 = it->second;
   it = mapper.find(parentOfIndex2);
   Node node2 = it->second;

   if(node1.index != node2.index){
       if(node1.rank >= node2.rank){
           parents[node2.index] = node1.index;
           if(node1.rank == node2.rank){
               node1.rank++;
           }
       } else {
           parents[node1.index] = node2.index;
       }

       return true;
   }
    return false;

}

int main(){

    ll nodes,edges,i,j,u,v,wt;
    cin>>nodes>>edges;

    // Here we will store the edges and their respective weights
    vector<pair<ll, pair<ll, ll> > > graph;

    for(i=0;i<edges;++i){
        cin>>u>>v>>wt;
        // Making the first element if pair as weight, so it is sorted according to it.
        graph.push_back(make_pair(wt,make_pair(u,v)));
    }

    sort(graph.begin(),graph.end());

    DisjointSet disjointSet;
    for(i=1;i<=nodes;i++){
        disjointSet.makeSet(i);
    }

    ll ans = 0;
    vector<pair<ll, ll > > mst;
    for(i=0;i<graph.size();i++){
        ll index1 = graph[i].second.first;
        ll index2 = graph[i].second.second;
        if(disjointSet.unionSet(index1,index2)){
            ans+=graph[i].first;
            mst.push_back(graph[i].second);
        }
    }

    cout<<"MST is:"<<endl;
    for(i=0;i<mst.size();++i){
        cout<<mst[i].first<<" "<<mst[i].second<<endl;
    }
    cout<<ans<<endl;
 }