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


 //-------------------------------------------------------
 //Q19. Shortest Path for unit weight Path in undirected Graph   
 vector<int> shortestUnit(int V, vector<vector<int>> &edges, int src) {
        // code here
        int E=edges.size();
        vector<vector<int>> adj(V);
        for(int i=0;i<E;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> dist(V,INT_MAX);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto nbr : adj[node]) {
                if (dist[node] + 1 < dist[nbr]) {
                    dist[nbr] = dist[node] + 1;
                    q.push(nbr);
                }
            }
        }
         for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        }
        return dist;
    }

//------------------------------------------------------------------------------
//Q. Dijkstraa Algo
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<pair<int,int>> adj[V];
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        //start of bfs
        vector<int> dist(V,INT_MAX);
        
        dist[src]=0;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
        p.push({0,src}); //insert in {dist,node}
        while(!p.empty()){
            int node=p.top().second;
            int w=p.top().first;
            p.pop();
            if (w > dist[node]) continue;
            for(auto i:adj[node]){
                if(w+i.second<dist[i.first]){
                    dist[i.first]=w+i.second;
                    p.push({dist[i.first],i.first});
                }
            }
        }
        return dist;
        
    }


// Q 20. Shortest Path using Dijkstra
 vector<int> pathSeq(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<int> parent(n+1,0);
        for(int i=0;i<n+1;i++){
            parent[i]=i;
        }
        vector<int> dist(n+1,INT_MAX);
        dist[1]=0;
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> p;
        p.push({0,1});
        while(!p.empty()){
            int node=p.top().second;
            int w=p.top().first;
            p.pop();
            if(w>dist[node])continue;
            
            for(auto i:adj[node]){
                if(i.second+w<dist[i.first]){
                    dist[i.first]=i.second+w;
                    parent[i.first]=node;
                    p.push({dist[i.first],i.first});
                }
            }
        }
        if(dist[n]==INT_MAX)return {-1};
        vector<int> ans;
        int curr=n;
        while(parent[curr]!=curr){
            ans.push_back(curr);
            curr=parent[curr];
        }
        ans.push_back(1);
        // ans.push_back(dist[n]);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }   

// Q21. Shortest path in binary matrix
int binaryPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[source.first][source.second]=0;
        queue<pair<int,pair<int,int>>>p;  //dist,{x,y}
        p.push({0,{source.first,source.second}});
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        while(!p.empty()){
            int d=p.front().first;
            int x=p.front().second.first;
            int y=p.front().second.second;
            p.pop();
            
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                
                if(nx<n && nx>=0 && ny<m && ny>=0 && grid[nx][ny]==1 && d+1<dist[nx][ny]){
                    dist[nx][ny]=d+1;
                    p.push({d+1,{nx,ny}});
                    
                    
                }
            }
            
        }
        if(dist[destination.first][destination.second]!=INT_MAX){
            return dist[destination.first][destination.second];
        }
        return -1;
    } 
//------------------------------------------
//Q23. Path with minimum efforts
int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>>
    > p;        
    p.push({0,{0,0}});
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        while(!p.empty()){
            
            int d=p.top().first;
            int x=p.top().second.first;
            int y=p.top().second.second;
            p.pop();
            if(d>dis[x][y])continue;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<n && nx>=0 && ny<m && ny>=0){
                    int nv=h[nx][ny];
                    int cv=h[x][y];
                    int diff=abs(cv-nv);
                    int newEff=max(d,diff);
                    if(newEff<dis[nx][ny]){

                        dis[nx][ny]=newEff;
                        p.push({newEff,{nx,ny}});
                    }
                }
            }
        }
        return dis[n-1][m-1];
        
    }

    
//--------------------------------------------------
//Q23. Minimum flights
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto i:flights){
            int u=i[0];
            int v=i[1];
            int price=i[2];
            adj[u].push_back({v,price});
        }
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        
        queue<pair<int,pair<int,int>>>p; //stops,node,price
                       
        p.push({0,{src,0}});
        while(!p.empty()){
            auto it= p.front();
            p.pop();
            int stops=it.first;
            int node=it.second.first;
            int price=it.second.second;
            
            if(stops>k)continue;
            
            for(auto i:adj[node]){
                int adjN=i.first;
                int w=i.second;
                
                if(w+price<dist[adjN] && stops<=k){
                    dist[adjN]=w+price;
                    p.push({stops+1,{adjN,dist[adjN]}});
                }
            }
        }
        
        
        
        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
        
        
    }
    


int main(){

}