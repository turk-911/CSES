#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
set<int> tPrimes;
struct Node {
    int x, y, dist;
};
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
bool isBoundary(int x, int y, int n, int m) {
    return x == 0 || y == 0 || x == n - 1 || y == m - 1;
}
pair<bool, string> escapeLabyrinth(vector<vector<char>> &grid, int n, int m) {
    int INF = 1e9;
    int dx[4] = {-1, 1, 0, 0}; 
    int dy[4] = {0, 0, -1, 1};
    char moveChar[4] = {'U', 'D', 'L', 'R'};
    vector<vector<int>> mdist(n, vector<int>(m, INF));
    queue<Node> mq, pq;

    pair<int, int> start;
    map<pair<int, int>, pair<int, int>> parent; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'M') {
                mq.push({i, j, 0});
                mdist[i][j] = 0;
            } else if (grid[i][j] == 'A') {
                start = {i, j};
            }
        }
    }

    while (!mq.empty()) {
        Node curr = mq.front();
        mq.pop();
        
        for (int k = 0; k < 4; k++) {
            int nx = curr.x + dx[k], ny = curr.y + dy[k];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != '#' && mdist[nx][ny] == INF) {
                mdist[nx][ny] = curr.dist + 1;
                mq.push({nx, ny, curr.dist + 1});
            }
        }
    }

    pq.push({start.first, start.second, 0});
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[start.first][start.second] = true;
    parent[start] = {-1, -1}; 

    while (!pq.empty()) {
        Node curr = pq.front();
        pq.pop();
        if (isBoundary(curr.x, curr.y, n, m)) {
            string path;
            pair<int, int> pos = {curr.x, curr.y};
            pair<int, int> supreme = {-1, -1};
            while (parent[pos] != supreme) {
                pair<int, int> prev = parent[pos];
                for (int k = 0; k < 4; k++) {
                    if (prev.first + dx[k] == pos.first && prev.second + dy[k] == pos.second) {
                        path += moveChar[k];
                        break;
                    }
                }
                pos = prev;
            }

            reverse(path.begin(), path.end());
            return {true, path};
        }

        for (int k = 0; k < 4; k++) {
            int nx = curr.x + dx[k], ny = curr.y + dy[k];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] != '#' && !visited[nx][ny]) {
                if (curr.dist + 1 < mdist[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.push({nx, ny, curr.dist + 1});
                    parent[{nx, ny}] = {curr.x, curr.y};
                }
            }
        }
    }

    return {false, ""};
}
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    pair<bool, string> result = escapeLabyrinth(grid, n, m);

    if (!result.first) {
        cout << "NO" << endl;
    }
    
    else {
        cout << "YES" << endl;
        cout << result.second.size() << endl;
        cout << result.second << endl;
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