#include <bits/stdc++.h>
#define int long long int
#define vi vector<int>
#define vc vector<char>
#define pii pair<int, int>
#define vvi vector<vi>
#define vvc vector<vc>
#define vpi vector<pii>
#define vb vector<bool>
#define vs vector<string>
#define pb push_back
#define mp make_pair
#define mii map<int, int>
#define qpii queue<pair<int, int>>
#define spii set<pair<int, int>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
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
    vb arr(1000001, false);
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
void dfs(int node, vvi &graph, vb &visited, vi &component, int comp_id) {
    visited[node] = true;
    component[node] = comp_id;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, component, comp_id);
        }
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    
    vvi graph(n);
    vb visited(n, false);
    vi component(n, -1);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; 
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int comp_id = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, component, comp_id++);
        }
    }
    
    vi representatives(comp_id);
    for (int i = 0; i < n; i++) {
        if (component[i] != -1 && representatives[component[i]] == 0) {
            representatives[component[i]] = i;
        }
    }
    
    cout << comp_id - 1 << endl;
    
    for (int i = 1; i < comp_id; i++) {
        cout << representatives[i - 1] + 1 << " " << representatives[i] + 1 << endl;
    }
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