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
void divide(int n, vector<pair<int, int>> &edges) {
    vector<vector<int>> graph(n + 1);
    vector<int> color(n + 1, -1);
    for(auto &[u, v]: edges) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    auto bfs = [&](int start) {
        queue<int> q;
        q.push(start);
        color[start] = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int neighbour: graph[node]) {
                if(color[neighbour] == -1) {
                    color[neighbour] = 3 - color[node];
                    q.push(neighbour);
                }
                else if(color[neighbour] == color[node]) {
                    cout << "IMPOSSIBLE" << endl;
                    return false;
                }
            }
        }
        return true;
    };
    for(int i = 1; i <= n; i++) {
        if(color[i] == -1) {
            if(bfs(i) == false) {
                return;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }
    cout << endl;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    divide(n, edges);
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