#include <bits/stdc++.h>
using namespace std;

//adjacency list
vector<vector<int>> adjList(int n,int m){
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}
//bfs traversal
void bfs(int f,int n,vector<vector<int>> &adj){
    //make a visited array
    vector<bool> vis(n+1,false); //initially all not visited;
    vector<int> ans;
    queue<int> q;
    
    vis[f]=true;
    ans.push_back(f);
    q.push(f);
    while(!q.empty()){
        int node=q.front();
        q.pop();

        for(auto i:adj[node]){
            if(!vis[i]){
                q.push(i);
                vis[i]=true;
                ans.push_back(i);
            }
        }

    }

    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return;
}
//dfs traversal
void dfs(int f, vector<vector<int>> &adj, vector<bool> &vis) {
    vis[f] = true;
    cout << f << " ";

    for (auto i : adj[f]) {
        if (!vis[i]) {
            dfs(i, adj, vis);
        }
    }
}



//-----------------------------------------------------------------------------------------------
//QUESTIONS

//1.Number of Provinces
int numProvince(vector<vector<int>> v,int n){
    vector<bool> vis(n,0);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            cnt++;
            dfs(i,v,vis);
        }
    }
    return cnt;
}

// 2. Number of Islands
void islandBfs(int row,int col, vector<vector<int>> &vis,vector<vector<char>>& grid){
    vis[row][col]=1;
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int>> q;
    q.push({row,col});
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        //now traversing in the neighbours
        //using loop technique to efficiently check the neighbours
        for(int di=-1;di<=1;di++){
            for(int dj=-1;dj<=1;dj++){
                int ni=r+di;
                int nj=c+dj;
                
                //validity check
                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]=='1' && vis[ni][nj]==0){
                    vis[ni][nj]=1;
                    q.push({ni,nj});
                }
            }
        }

    }
}


int numIslands(vector<vector<char>>& grid){  // 0--> water | 1---> land
 int n=grid.size();
 int m=grid[0].size();
 int ans=0;
 vector<vector<int>> vis(n,vector<int>(m,0));
 for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(!vis[i][j] && grid[i][j]=='1'){

            islandBfs(i,j,vis,grid);
            ans++;
        }

    }
 }

 return ans;
}


//---------------------------------------------------------
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v=adjList(n,m);


}