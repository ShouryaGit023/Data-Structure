#include <bits/stdc++.h>
using namespace std;


//Q18. Shortest path for each node using topo sort
void topoSort(int node,vector<pair<int,int>> adj[],int vis[],stack<int> s){
    vis[node]=1;
    for(auto i:adj[node]){
        int v=i.first;
        if(!vis[v]){
            topoSort(v,adj,vis,s);
        }
    }
    s.push(node);

}

vector<int> shortestPath(int n,int m,vector<int>edges[]){
    vector<pair<int,int>> adj[n];
    for(int i=0;i<n;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        adj[u].push_back({v,wt});
    }

    //finding the topo sort
    int vis[n]={0};
    stack<int> s;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topoSort(i,adj,vis,s);
        }
    }

    //stack is filled in topo sort order
    // now do the distance thing
    vector<int> dist(n,INT_MAX);
    dist[0]=0;
    while(!s.empty()){
        int node=s.top();
        s.pop();

        for(auto i:adj[node]){
            int v=i.first;
            int wt=i.second;
            //relaxation of graph

            if(dist[node]+wt<dist[v]){
                dist[v]=dist[node]+wt;
            }
        }
    }
    return dist;



}


int main(){

}