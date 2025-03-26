#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;

class Graph {
    int V;
    vector<vector<int>> adj;
    vector<vector<int>> rev_adj;
    
    vector<bool> visited;
    stack<int> st;
    
    vector<vector<int>> strongly_connected_components;
    
    void dfs1(int node) {
        visited[node] = true;
        
        for(int neighbour: adj[node]) {
            if(!visited[neighbour]) {
                dfs1(neighbour);
            }
        }
        st.push(node);
    }
    
    void dfs2(int node, vector<int> &component) {
        visited[node] = true;
        component.push_back(node);
        
        for(int neighbour: rev_adj[node]) {
            if(!visited[neighbour]) {
                dfs2(neighbour, component);
            }
        }
    }
    
    public:
    vector<int> kingdoms;
    int kingdom_id = 1;
    
    Graph(int V): V(V) {
        adj.resize(V);
        rev_adj.resize(V);
        kingdoms.resize(V, -1);
    }
    
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }
    
    void find_strongly_connected_components() {
        visited.assign(V, false);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs1(i);
            }
        }
        
        visited.assign(V, false);
        
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            if(!visited[node]) {
                vector<int> component;
                dfs2(node, component);
                strongly_connected_components.push_back(component);
                
                int n = component.size();
                for(int i = 0; i < n; i++) {
                    kingdoms[component[i]] = kingdom_id;
                }
                
                kingdom_id++;
            }
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    
    Graph g(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        
        g.add_edge(u, v);
    }
    
    g.find_strongly_connected_components();
    vector<int> kingdoms = g.kingdoms;
    
    cout << g.kingdom_id-1 << endl;
    
    for(int k: kingdoms) {
        cout << k << " ";
    }
    
    cout << endl;
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