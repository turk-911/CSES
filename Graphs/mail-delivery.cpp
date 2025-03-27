#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    unordered_map<int, multiset<int>> graph;
    vector<int> circuit;
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        graph[u].insert(v);
        graph[v].insert(u);
    }
    
    for(auto &[node, edges]: graph) {
        if(edges.size() % 2 != 0) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    
    int one = 1;
    
    stack<int> st;
    st.push(one);
    
    while(!st.empty()) {
        int u = st.top();
        
        if(!graph[u].empty()) {
            int v = *graph[u].begin();
            graph[u].erase(graph[u].find(v));
            graph[v].erase(graph[v].find(u));
            st.push(v);
        }
        
        else {
            circuit.push_back(u);
            st.pop();
        }
    }
    
    int cs = circuit.size();
    if(cs != m+1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    
    for(int i = 0; i < cs; i++) {
        cout << circuit[i] << " "; 
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