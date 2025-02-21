#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
set<int> tPrimes;
int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
int csum(int a) {
    return (a * (a + 1)) / 2;
}
void precalc() {
    vector<bool> arr(1000001, false);
    arr[0] = arr[1] = true;
    for (int i = 2; i * i < 1000001; i++) {
        if (!arr[i]) {
            for (int j = i * i; j < 1000001; j += i) {
                arr[j] = true;
            }
        }
    }
    for (int i = 0; i < 1000001; i++) {
        if (!arr[i]) tPrimes.insert(i * i);
    }
}
int nCr(int n, int r, vector<vector<int>> &dp) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    if(dp[n][r] != -1) return dp[n][r];
    return dp[n][r] = nCr(n-1, r, dp) + nCr(n-1, r-1, dp);
}

int power(int x, unsigned int y, int p) {
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
string DecimalToBinary(int num) {
    string str;
    while (num) {
        if (num & 1) str += '1';
        else str += '0';
        num >>= 1;
    }
    return str;
}
int factorial(int a) {
    int p = 1;
    for (int i = 2; i <= a; i++) p = p * i;
    return p;
}
bool dfs(int node, int parent, vector<bool> &visited, unordered_map <int, vector<int>> &graph, unordered_map<int, int> &parentMap, vector<int> &cycle) {
    visited[node] = true;
    for(int neighbour: graph[node]) {
        if(visited[neighbour] == false) {
            parentMap[neighbour] = node;
            if(dfs(neighbour, node, visited, graph, parentMap, cycle) == true) {
                return true;
            }
        }
        else if(neighbour != parent) {
            int curr = node;
            while(curr != neighbour) {
                cycle.push_back(curr);
                curr = parentMap[curr];
            }
            cycle.push_back(neighbour);
            return true;
        }
    }
    return false;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    unordered_map<int, vector<int>> graph;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> cycle;
    vector<bool> visited(n, false);
    unordered_map<int, int> parentMap;
    for(int i = 0; i < n; i++) {
        if(visited[i] == false && dfs(i, -1, visited, graph, parentMap, cycle)) {
            int k = cycle.size();
            cout << k + 1 << endl;
            for(int node: cycle) {
                cout << node << " ";
            }
            cout << cycle[0] << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
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