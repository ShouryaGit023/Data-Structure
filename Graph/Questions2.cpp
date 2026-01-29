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


int main(){

}