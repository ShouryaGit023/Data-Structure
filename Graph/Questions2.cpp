#include <bits/stdc++.h>
using namespace std;

//Q7.Surround Regions
void replaceBFS(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &grid){
    int n=grid.size();
    int m=grid[0].size();
    vis[i][j]=1;
    queue<pair<int,int>>q;
    q.push({i,j});
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    while(!q.empty()){
        int id=q.front().first;
        int jd=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ni=id+dx[i];
            int nj=jd+dy[i];

            if(ni<n && ni>=0 && nj>=0 && nj<m && grid[ni][nj]==0 && vis[ni][nj]==0){
                q.push({ni,nj});
                vis[ni][nj]=1;
            }
        }
    }

}

vector<vector<int>> replace(vector<vector<int>> grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int i = 0; i < n; i++){
        if(grid[i][0] == 0 && !vis[i][0]) replaceBFS(i,0,vis,grid);
        if(grid[i][m-1] == 0 && !vis[i][m-1]) replaceBFS(i,m-1,vis,grid);
    }

    for(int j = 0; j < m; j++){
        if(grid[0][j] == 0 && !vis[0][j]) replaceBFS(0,j,vis,grid);
        if(grid[n-1][j] == 0 && !vis[n-1][j]) replaceBFS(n-1,j,vis,grid);
    }
    vector<vector<int>> ans(n,vector<int>(m,1));
   for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if(grid[i][j] == 0 && vis[i][j] == 1){
            ans[i][j] = 0;   // keep safe O
        }
        // else remains 1 (X)
    }
}
    return ans;
}


//Q8. Number of Encalves
void encalveBFS(int i,int j,vector<vector<int>> &vis,vector<vector<int>> &grid){
    int n=grid.size();
    int m=grid[0].size();
    vis[i][j]=1;
    queue<pair<int,int>>q;
    q.push({i,j});
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    while(!q.empty()){
        int id=q.front().first;
        int jd=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ni=id+dx[i];
            int nj=jd+dy[i];

            if(ni<n && ni>=0 && nj>=0 && nj<m && grid[ni][nj]==1 && vis[ni][nj]==0){
                q.push({ni,nj});
                vis[ni][nj]=1;
            }
        }
    }


}

int encalves(vector<vector<int>> grid){
    int n=grid.size();
    int m=grid[0].size();
    int ans=0;
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int i = 0; i < n; i++){
        if(grid[i][0] == 1 && !vis[i][0]) encalveBFS(i,0,vis,grid);
        if(grid[i][m-1] == 1 && !vis[i][m-1]) encalveBFS(i,m-1,vis,grid);
    }

    for(int j = 0; j < m; j++){
        if(grid[0][j] == 1 && !vis[0][j]) encalveBFS(0,j,vis,grid);
        if(grid[n-1][j] == 1 && !vis[n-1][j]) encalveBFS(n-1,j,vis,grid);
    }
    
   for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if(grid[i][j] == 1 && vis[i][j] == 0){
            ans++;  
        }
        
    }
}
    return ans;

}

//Q9. Bipartite Graph
bool isBipartite(int src,vector<int>adj[]){
    queue<int> q;
    int c[src];
    q.push(0); //0- based indexing of graph
    for(int i=0;i<src;i++){
        c[i]=-1;
    }
    c[0]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto i:adj[node]){
            if(c[i]==-1){
                c[i]=!c[node];
                q.push(i);
            }
            else if(c[i]==c[node]){
                return false;
            }
        }
    }
    return true;

}

//Q10. Cycle in Directed Graph
bool dfs(int node,vector<int> adj[],int vis[],int pathVis[]){
    vis[node]=1;
    pathVis[node]=1;

    //traverse for adj node
    for(auto i:adj[node]){
        if(!vis[i]){
            if(dfs(i,adj,vis,pathVis)==true)return true;
        }
        else if(pathVis[i]){
            return true;
        }
    }

    //when going back undo the pathVis
    pathVis[node]=0;
    return false;

}
bool isCyclic(int v,vector<int> adj[]){
    int vis[v]={0};
    int pathVis[v]={0};
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,pathVis)==true)return true;
        }
    }
    return false;
}


//Q11. Find the eventual Safe states
bool dfs(int node,vector<vector<int>> & adj,vector<int> &vis,vector<int>&pathVis,vector<int> &check){
    vis[node]=1;
    pathVis[node]=1;
    check[node]=0;

    //traverse for adj node
    for(auto i:adj[node]){
        if(!vis[i]){
            if(dfs(i,adj,vis,pathVis,check)==true){
                check[node]=0;
                return true;
            }
        }
        else if(pathVis[i]){
            check[node]=0;
            return true;
        }
    }

    //when going back undo the pathVis
    check[node]=1;
    pathVis[node]=0;
    return false;

}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> vis(v,0);
    vector<int>pathVis(v,0);
    vector<int> check(v,0);
    vector<int> safe;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(dfs(i,graph,vis,pathVis,check));
        }
    }
    for(int i=0;i<v;i++){
        if(check[i]==1){
            safe.push_back(i);
        }
    }
    return safe;
    
        
    }



    //Q12. TopoLogical Sorting

void topoDFS(int src,vector<vector<int>> &adj,vector<int>&vis, stack<int> &s){
    vis[src]=1;
    for(auto i: adj[src]){
        if(!vis[i]){

            topoDFS(i,adj,vis,s);
        }
    }
    s.push(src);
}
vector<int> topoSort(vector<vector<int>> &adj){
    int v=adj.size();
    vector<int> vis(v,0);
    stack<int> s;
    for(int i=0;i<v;i++){
        if(vis[i]==0){
            topoDFS(i,adj,vis,s);
        }
    }
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;

}
//--------------------------------------------------------------
//Q13. Kahns Algo

vector<int> kahn(int v,vector<vector<int>> adj){
    vector<int> indeg(v,0);
    for(int i=0;i<v;i++){
        for(auto j:adj[i]){
            indeg[j]++;
        }
    }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto i:adj[node]){
            indeg[i]--;
            if(indeg[i]==0){
                q.push(i);
            }
        }
        
    }
    return ans;
}

//-------------------------------------------------
bool cycleTopo(int v,vector<vector<int>> adj){
    vector<int> indeg(v,0);
    for(int i=0;i<v;i++){
        for(auto j:adj[i]){
            indeg[j]++;
        }
    }

    queue<int> q;
    for(int i=0;i<v;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    vector<int> topovec;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topovec.push_back(node);
        for(auto i:adj[node]){
            indeg[i]--;
            if(indeg[i]==0){
                q.push(i);
            }
        }
    }

    return ((int)topovec.size()!=v);

}

//----------------------------------------
//Q16 Eventual Using Kahn
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> adj(n);
        vector<int> indeg(n,0);
        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                adj[v].push_back(u);  // reverse edge
                indeg[u]++;           // outdegree count
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto i:adj[node]){
                indeg[i]--;
                if(indeg[i]==0){
                    q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }

    //-------------------------------------------
    //Q17---> Alien Dictionary
string findOrder(vector<string> &dict) {
        vector<vector<int>> adj(26);
        vector<int> indeg(26, 0);
        vector<bool> present(26, false);

        int n = dict.size();

        // mark present characters
        for (auto &w : dict)
            for (char c : w)
                present[c - 'a'] = true;

        // build graph
        for (int i = 0; i < n - 1; i++) {
            string &a = dict[i];
            string &b = dict[i + 1];
            int len = min(a.size(), b.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (a[j] != b[j]) {
                    adj[a[j] - 'a'].push_back(b[j] - 'a');
                    indeg[b[j] - 'a']++;
                    found = true;
                    break;
                }
            }

            // invalid prefix case
            if (!found && a.size() > b.size())
                return "";
        }

        // Kahn's algorithm
        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (present[i] && indeg[i] == 0)
                q.push(i);
        }

        string ans;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            ans.push_back(char(u + 'a'));

            for (int v : adj[u]) {
                if (--indeg[v] == 0)
                    q.push(v);
            }
        }

        // cycle check
        for (int i = 0; i < 26; i++)
            if (present[i] && indeg[i] > 0)
                return "";

        return ans;
    }

    //--------------------------


int main(){
//Graphs and application
}