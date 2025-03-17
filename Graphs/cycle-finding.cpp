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
void findCycle(int n, vector<pair<pair<int, int>, int>> &edges) {
    vector<int> dist(n, 1e9);
    vector<int> parent(n, -1);
    vector<bool> inCycle(n, false);
    dist[0] = 0;
    int last = -1;
    for(int i = 0; i < n; i++) {
        for(auto edge: edges) {
            int u = edge.first.first;
            int v = edge.first.second;
            int wt = edge.second;
            if(dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                parent[v] = u;
            }
        }
    }
    for(auto edge: edges) {
        int u = edge.first.first;
        int v = edge.first.second;
        int wt = edge.second;
        if(dist[u] != 1e9 && dist[u] + wt < dist[v]) {
            last = v;
        }
    }
    if(last == -1) {
        cout << "NO" << endl;
        return;
    }
    int node = last;
    for(int i = 0; i < n; i++) {
        node = parent[node];
    }
    vector<int> cycle;
    int start = node;
    do {
        cycle.push_back(start);
        inCycle[node] = true;
        start = parent[start];
    } while(node != start);
    cout << "YES" << endl;
    for(int a: cycle) {
        cout << a + 1 << " ";
    }
    cout << cycle[0] + 1 << endl;
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, int>> edges;
    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        u--;
        v--;
        edges.push_back({{u, v}, wt});
    }
    findCycle(n, edges);
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