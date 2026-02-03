#include <bits/stdc++.h>
using namespace std;


//Q18. Shortest path for each node using topo sort
void topoSort(int node,vector<pair<int,int>>adj[],vector<int>& vis,stack<int> &s){
      vis[node]=1;
      for(auto i:adj[node]){
          int v=i.first;
          int w=i.second;
          if(!vis[v]){
              topoSort(v,adj,vis,s);
          }
      }
      s.push(node);
  }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>> adj[V];
        for(int i=0;i<E;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
        }
        
        //finding the topo sort
        vector<int> vis(V,0);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topoSort(i,adj,vis,s);
            }
        }
        
        //distance vector
        vector<int> dist(V,INT_MAX);
        dist[0]=0;
        while(!s.empty()){
            int node=s.top();
            s.pop();

            //to check for unreachable nodes
             if (dist[node] == INT_MAX) continue;

          for (auto &it : adj[node]) {
              int v = it.first;
              int w = it.second;

              if (dist[node] + w < dist[v]) {
                  dist[v] = dist[node] + w;
              }
          }
      }
      //distance to unreachable node is -1
            for(auto &i:dist){
                if(i==INT_MAX){
                    i=-1;
                }
            }
            return dist;
    }


int main(){

}