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
void solve() {
    int n, m;
    cin >> n >> m;
    vpi edges(m);
    for(int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }
    vvi adjList(n + 1);
    for(auto &[u, v]: edges) {
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    vi parent(n + 1, -1);
    vi distance(n + 1, -1);
    queue<int> q;
    q.push(1);
    parent[1] = -1;
    distance[1] = 1;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int neighbour: adjList[node]) {
            if(distance[neighbour] == -1) {
                parent[neighbour] = node;
                distance[neighbour] = distance[node] + 1;
                q.push(neighbour);
            }
        }
    }
    if(distance[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vi path;
    int node = n;
    while(parent[node] != -1) {
        path.pb(node);
        node = parent[node];
    }
    int sz = path.size();
    reverse(all(path));
    sz++;
    cout << sz << endl;
    cout << 1 << " ";
    sz--;
    for(int i = 0; i < sz; i++) {
        cout << path[i] << " ";
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