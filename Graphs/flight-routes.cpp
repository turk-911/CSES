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
    int cost;
    int city;
    bool operator>(const Node &other) const {
        return cost > other.cost;
    }
};
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<priority_queue<int>> shortest_paths(n+1);
    pq.push({0, 1});
    shortest_paths[1].push(0);
    
    vector<vector<int>> res;
    
    while(!pq.empty()) {
        auto [cost, city] = pq.top();
        pq.pop();
        
        if(city == n) {
            res.push_back({cost});
            if(res.size() == k) {
                break;
            }
        }
        
        for(auto [next_city, wt]: adj[city]) {
            int new_cost = cost + wt;
            if(shortest_paths[next_city].size() < k) {
                shortest_paths[next_city].push(new_cost);
                pq.push({new_cost, next_city});
            }
            else if(shortest_paths[next_city].top() > new_cost) {
                shortest_paths[next_city].pop();
                shortest_paths[next_city].push(new_cost);
                pq.push({new_cost, next_city});
            }
        }
    }
    
    for(auto &r: res) {
        cout << r[0] << " ";
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