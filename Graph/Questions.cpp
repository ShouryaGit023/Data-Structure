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



int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v=adjList(n,m);


}