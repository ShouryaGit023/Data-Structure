#include <bits/stdc++.h>
using namespace std;

// MINIMUM SPANNING TREE
//Q1. Sum of the mst
int spanningTree(int V, vector<vector<int>>& edges) {
        // Step 1: Build adjacency list
        vector<vector<pair<int,int>>> adj(V);
        
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Step 2: Min-heap {weight, node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> vis(V, 0);
        pq.push({0, 0});   // {weight, node}

        int sum = 0;

        // Step 3: Prim's Algorithm
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int wt = top.first;
            int node = top.second;

            if (vis[node]) continue;

            vis[node] = 1;
            sum += wt;

            for (auto &it : adj[node]) {
                int adjNode = it.first;
                int adjW = it.second;
                if (!vis[adjNode]) {
                    pq.push({adjW, adjNode});
                }
            }
        }

        return sum;
    }

//-----------------------------------------
// DSU
class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n);
        rankv.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by rank
    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;

        if (rankv[pu] < rankv[pv])
            parent[pu] = pv;
        else if (rankv[pv] < rankv[pu])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rankv[pu]++;
        }
    }
};

//---------------------------------------------------------
// Kruskal Algo
int kruskalsMST(int V, vector<vector<int>> &edges) {
        DSU d(V);
        int ans = 0;

        // {weight, {u, v}}
        vector<pair<int, pair<int,int>>> ed;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            ed.push_back({w, {u, v}});
        }

        sort(ed.begin(), ed.end());

        for (auto &e : ed) {
            int u = e.second.first;
            int v = e.second.second;
            int w = e.first;

            if (d.find(u) != d.find(v)) {
                d.unite(u, v);
                ans += w;
            }
        }

        return ans;
    }

//---------------------------------------------
// Finding number of Components using DSU
int findCircleNum(vector<vector<int>>& v) {
        int n = v.size();
        DSU d(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) { 
                if (v[i][j] == 1) {
                    d.unite(i, j); 
                }
            }
        }

        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(d.find(i));
        }

        return s.size();
    }

int main(){

}