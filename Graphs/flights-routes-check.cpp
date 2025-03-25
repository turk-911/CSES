#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;
    for(int neighbour: adj[node]) {
        if(!visited[neighbour]) {
            dfs(neighbour, adj, visited);
        }
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    vector<vector<int>> rev_adj(n+1);
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }
    
    vector<bool> visited1(n+1, false);
    int source = 1;
    
    dfs(source, adj, visited1);
    
    int node1 = -1;
    for(int i = 1; i <= n; i++) {
        if(!visited1[i]) {
            node1 = i;
            break;
        }
    }
    
    if(node1 == -1) {
        vector<bool> visited2(n+1, false);
        dfs(source, rev_adj, visited2);
    
        int node2 = -1;
        for(int i = 1; i <= n; i++) {
            if(!visited2[i]) {
                node2 = i;
                break;
            }
        }
        
        if(node2 == -1) {
            cout << "YES" << endl;
            return;
        }
        
        cout << "NO" << endl;
        cout << node2 << " " << source << endl;
        return;
    }
    
    cout << "NO" << endl;
    cout << source << " " << node1 << endl;
    
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