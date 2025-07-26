#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void build(int ind, int lo, int hi, vector<int> &arr, vector<int> &tree) {
    if(lo == hi) {
        tree[ind] = arr[lo];
        return;
    }
    int mid = (lo+hi) >> 1;
    build(2*ind+1, lo, mid, arr, tree);
    build(2*ind+2, mid+1, hi, arr, tree);
    tree[ind] = tree[2*ind+1] + tree[2*ind+2];
}
int query(int ind, int lo, int hi, int l, int r, vector<int> &arr, vector<int> &tree) {
    if(lo >= l && hi <= r) {
        return tree[ind];
    }
    if(hi < l || lo > r) {
        return 0;
    }
    int mid = (lo+hi) >> 1;
    int left = query(2*ind+1, lo, mid, l, r, arr, tree);
    int right = query(2*ind+2, mid+1, hi, l, r, arr, tree);
    return left+right;
}
void update(int ind, int lo, int hi, int pos, int val, vector<int> &tree) {
    if(lo == hi) {
        tree[ind] = val;
        return;
    }
    int mid = (lo+hi) >> 1;
    if(pos <= mid) {
        update(2*ind+1, lo, mid, pos, val, tree);
    }
    else {
        update(2*ind+2, mid+1, hi, pos, val, tree);
    }
    tree[ind] = tree[2*ind+1] + tree[2*ind+2]; 
}
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> tree(4*n+5);
    build(0, 0, n-1, arr, tree);
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int k, u;
            cin >> k >> u;
            k--;
            update(0, 0, n-1, k, u, tree);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << query(0, 0, n-1, l, r, arr, tree) << endl;
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    // precalc();
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}