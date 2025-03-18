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
struct Node {
    int to, cost;
};
void solve() {
    int n, m;
    cin >> n >> m;
    int inf = 1e18;
    
    vector<vector<Node>> graph(n+1);
    
    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        graph[u].push_back({v, wt});
    }
    
    vector<int> dist(n+1, inf);
    vector<int> ways(n+1, 0);
    vector<int> min_flights(n+1, 0);
    vector<int> max_flights(n+1, 0);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[1] = 1;
    ways[1] = 1;
    pq.push({0, 1});
    
    while(!pq.empty()) {
        auto [d, node] = pq.top();
        pq.pop();
        
        if(d > dist[node]) {
            continue;
        }
        
        for(auto edge: graph[node]) {
            int next_node = edge.to;
            int new_cost = edge.cost+d;
            
            if(new_cost < dist[next_node]) {
                dist[next_node] = new_cost;
                ways[next_node] = ways[node];
                min_flights[next_node] = min_flights[node]+1;
                max_flights[next_node] = max_flights[node]+1;
                pq.push({new_cost, next_node});
            }
            
            else if(new_cost == dist[next_node]) {
                ways[next_node] = (ways[next_node]+ways[node]) % mod;
                min_flights[next_node] = min(min_flights[next_node], 1+min_flights[node]);
                max_flights[next_node] = max(max_flights[next_node], 1+max_flights[node]);
            }
        }
    }
    
    cout << dist[n] << " " << ways[n] << " " << min_flights[n] << " " << max_flights[n] << endl;
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