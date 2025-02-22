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
int dijkstra(int start, int end, vector<vector<pair<int, int>>> &adj, int n) {
    vector<vector<int>> dist(n + 1, vector<int>(2, 1e18));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    dist[start][0] = 0;
    pq.push({0, {start, 0}});
    while(!pq.empty()) {
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        int cost = p.first;
        int node = p.second.first;
        int state = p.second.second;
        if(cost > dist[node][state]) {
            continue;
        }
        for(auto edge: adj[node]) {
            int next = edge.first;
            int wt = edge.second;
            if(dist[next][state] > cost + wt) {
                dist[next][state] = cost + wt;
                pq.push({dist[next][state], {next, state}});
            }
            if(state == 0) {
                int discountedCost = cost + wt / 2;
                if(dist[next][1] > discountedCost) {
                    dist[next][1] = discountedCost;
                    pq.push({dist[next][1], {next, 1}});
                }
            }
        }
    }
    return min(dist[end][0], dist[end][1]);
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    int ans = dijkstra(1, n, adj, n);
    cout << ans << endl;
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