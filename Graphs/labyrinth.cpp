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
#define pipii pair<int, pii>
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
    vector<vector<int>> distance(n, vector<int>(m, 1e9));
    vector<vector<char>> matrix(n, vector<char>(m, ' '));
    vector<vector<char>> prevDirections(n, vector<char>(m, '$'));
    pii source, destination;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'A') {
                source = {i, j};
            }
            if (matrix[i][j] == 'B') {
                destination = {i, j};
            }
        }
    }

    set<pair<int, pii>> s; 
    s.insert({0, source});
    int srow = source.first, scol = source.second;
    distance[srow][scol] = 0;

    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};
    char directions[4] = {'U', 'R', 'D', 'L'};

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[srow][scol] = true;

    while (!s.empty()) {
        auto top = *s.begin();
        s.erase(s.begin()); 
        int dist = top.first;
        pii coordinates = top.second;
        int row = coordinates.first;
        int col = coordinates.second;

        if (coordinates == destination) {
            string path = "";
            while (row != source.first || col != source.second) {
                path = prevDirections[row][col] + path;
                for (int i = 0; i < 4; i++) {
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];
                    if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m &&
                        distance[nrow][ncol] == dist - 1) {
                        row = nrow;
                        col = ncol;
                        dist--;
                        break;
                    }
                }
            }
            cout << "YES" << endl;
            cout << distance[destination.first][destination.second] << endl;
            cout << path << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int ncol = col + delcol[i];
            int nrow = row + delrow[i];

            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && (matrix[nrow][ncol] == '.' || matrix[nrow][ncol] == 'B') && !visited[nrow][ncol]) {

                if (distance[nrow][ncol] > dist + 1) {
                    if (distance[nrow][ncol] != 1e9) {
                        s.erase({distance[nrow][ncol], {nrow, ncol}});
                    }
                    distance[nrow][ncol] = dist + 1;
                    prevDirections[nrow][ncol] = directions[i];
                    s.insert({distance[nrow][ncol], {nrow, ncol}});
                    visited[nrow][ncol] = true;
                }
            }
        }
    }

    cout << "NO" << endl;
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