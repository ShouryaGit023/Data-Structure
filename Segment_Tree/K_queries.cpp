#include <bits/stdc++.h>
using namespace std;

template <typename T>
class MergeSortTree {
private:
    int n;
    vector<std::vector<T>> tree;

    // In a Merge Sort Tree, merging means combining two sorted lists
    void merge_nodes(int node, int left, int right) {
        merge(tree[left].begin(), tree[left].end(),
                   tree[right].begin(), tree[right].end(),
                   back_inserter(tree[node]));
    }

    void build(const std::vector<T>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node].push_back(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        
        // Reserve memory to avoid multiple reallocations
        tree[node].reserve(tree[2 * node].size() + tree[2 * node + 1].size());
        merge_nodes(node, 2 * node, 2 * node + 1);
    }

    // Returns count of elements strictly GREATER than k in range [l, r]
    int query(int node, int start, int end, int l, int r, T k) {
        if (r < start || end < l) return 0;
        
        if (l <= start && end <= r) {
            // Binary search to find elements > k
            return tree[node].end() - std::upper_bound(tree[node].begin(), tree[node].end(), k);
        }
        
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r, k) + 
               query(2 * node + 1, mid + 1, end, l, r, k);
    }

public:
    MergeSortTree(const std::vector<T>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    int query(int l, int r, T k) {
        return query(1, 0, n - 1, l, r, k);
    }
};


int main(){
    int n;cin>>n;
    int q;cin>>q;
    vector<int> v(n);
    for(auto &i:v){
        cin>>i;
    }
    MergeSortTree<int> seg(v);
    while(q--){
        int l,r,x;
        cin>>l>>r>>x;
        cout<<seg.query(l-1,r-1,x)<<endl;
    }
    cout<<endl;
}