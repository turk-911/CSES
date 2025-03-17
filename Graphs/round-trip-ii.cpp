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
bool dfs(int node, int &start, int &end, vector<int> &visited, vector<int> &parent, vector<vector<int>> &adj) {
    visited[node] = 1;
    for(int next: adj[node]) {
        if(visited[next] == 0) {
            parent[next] = node;
            if(dfs(next, start, end, visited, parent, adj)) {
                return true;
            }
        }
        else if(visited[next] == 1) {
            start = next;
            end = node;
            return true;
        }
    }
    visited[node] = 2;
    return false;
}
void find_cycle(int n, vector<vector<int>> &adj) {
    vector<int> parent(n+1, -1);
    vector<int> visited(n+1, 0);
    int start = -1;
    int end = -1;
    
    for(int i = 1; i <= n; i++) {
        if(!visited[i] && dfs(i, start, end, visited, parent, adj)) {
            break;
        }
    }
    
    if(start == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    
    vector<int> cycle;
    cycle.push_back(start);
    
    for(int v = end; v != start; v = parent[v]) {
        cycle.push_back(v);
    }
    
    cycle.push_back(start);
    reverse(cycle.begin(), cycle.end());
    
    int s = cycle.size();
    cout << s << endl;
    for(int city: cycle) {
        cout << city << " ";
    }
    
    cout << endl;
}
void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    find_cycle(n, adj);
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