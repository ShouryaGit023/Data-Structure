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

// 3. Flood Fill
void dfs(int sr,int sc,vector<vector<int>> &copyImage,vector<vector<int>>&image, int newColor,int dx[],int dy[],int iniColor){
    int n=image.size();
    int m=image[0].size();
    copyImage[sr][sc]=newColor;
    //check for neighbour
    for(int i=0;i<4;i++){
        int nr=sr+dx[i];
        int nc=sc+dy[i];

        if(nr>=0 && nr<n && nc>=0 && nc<m && copyImage[nr][nc]==iniColor && copyImage[nr][nc]!=newColor){
            dfs(nr,nc,copyImage,image,newColor,dx,dy,iniColor);
        }
    }
    

}

 vector<vector<int>> floodFill(vector<vector<int>> &image,int sr,int sc,int newColor){
    vector<vector<int>> copyImage=image;
    int n=image.size();
    int m=image[0].size();
    int color=image[sr][sc];
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
    dfs(sr,sc,copyImage,image,newColor,dx,dy,color);
    return copyImage;


 }

 // ✅Equivalent bfs code
    void floodBfs(int sr, int sc, vector<vector<int>>& image,int oldColor, int newColor) {

        int n = image.size();
        int m = image[0].size();

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c=q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    image[nr][nc] == oldColor) {
                    
                    image[nr][nc] = newColor;
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor == newColor) return image;

        floodBfs(sr, sc, image, oldColor, newColor);
        return image;
    }

    //----------------------------------------------------------------------------------------------
int orangeRotting(vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<pair<int,int>,int>>q; //stores in form of r,c,time
    vector<vector<int>> vis;
    int ans=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=2;
            }
            else{
                vis[i][j]=0;
            }
        }
    }
    int tm=0;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,-1,0,1};
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int t=q.front().second;
        tm=max(tm,t);
        q.pop();

        for(int i=0;i<4;i++){
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(nr<n && nr>=0 && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]!=2){
                q.push({{nr,nc},++t});

            }
        }

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]!=2 && grid[i][j]==1){
                return -1;
            }
        }
    }
    return tm;
}

//------------------------------------------------------------------
//5. Cycle in the Graph
// BFS
bool isCycleBFS(int v, vector<int> adj[]){
    
}



//---------------------------------------------------------
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v=adjList(n,m);


}