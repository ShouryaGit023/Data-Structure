#include <bits/stdc++.h>
using namespace std;

//representation using adjacency matrix
void adjGraph(int n, int m) {
    vector<vector<int>> adj(n+1, vector<int>(n+1, 0));

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> adjList(int n,int m){
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        // below is only when undirected graph
        // for directed we will only have u---->v 
        adj[v].push_back(u);
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << i << " -> ";
    //     for (int v : adj[i]) {
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }
    return adj;
}

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


int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v=adjList(n,m);
    bfs(1,n,v);

        for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int v : v[i]) {
            cout << v << " ";
        }
        cout << endl;
    }



    return 0;
}

