#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
class DSU {
    public:
    vector<int> parent;
    vector<int> size;
    int components;
    int largest;
    
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        components = n;
        largest = 1;
        
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if(parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    
    void union_find(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        
        if(root_a != root_b) {
            if(size[root_a] < size[root_b]) {
                swap(root_b, root_a);
            }
            parent[root_b] = root_a;
            size[root_a] += size[root_b];
            largest = max(largest, size[root_a]);
            components--;
        }
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    
    DSU dsu(n);
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        dsu.union_find(u, v);
        cout << dsu.components << " " << dsu.largest << endl;
    }
    
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    // precalc();
    for (int i = 1; i <= t; i++) solve();
    return 0;
}