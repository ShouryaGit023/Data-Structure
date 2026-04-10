#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SegmentTree {
private:
    int n;
    vector<T> tree;
    T neutral = 0; // Change based on operation: 0 for sum, LLONG_MAX for min, etc.

    // The core operation logic
    T merge(T a, T b) {
        return a + b; // Change this to std::min(a, b), a ^ b, std::gcd(a, b), etc.
    }

    void build(const std::vector<T>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(arr, 2 * node, start, mid);
        build(arr, 2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, T val) {
        if (start == end) {
            tree[node] = val; // For increment: tree[node] += val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    T query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return neutral;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        T p1 = query(2 * node, start, mid, l, r);
        T p2 = query(2 * node + 1, mid + 1, end, l, r);
        return merge(p1, p2);
    }

public:
    SegmentTree(const std::vector<T>& arr) {
        n = arr.size();
        tree.assign(4 * n, neutral);
        build(arr, 1, 0, n - 1);
    }

    void update(int idx, T val) {
        update(1, 0, n - 1, idx, val);
    }

    T query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};