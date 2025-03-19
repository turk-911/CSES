#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1e9+7;
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
int mod_inv(int a) {
    int res = 1;
    int b = mod-2;
    while(b > 0) {
        if(b&1) {
            res = (res*a) % mod;
        }
        a = (a*a) % mod;
        b >>= 1;
    }
    return res;
}
void solve() {
    int n;
    cin >> n;
    int sum = n * (n+1) / 2;
    
    if(sum & 1) {
        cout << 0 << endl;
        return;
    }
    
    int target = sum / 2;
    vector<int> dp(target+1, 0);
    dp[0] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = target; j >= i; j--) {
            dp[j] = (dp[j]+dp[j-i]) % mod;
        }
    }
    
    
    int ans = (dp[target] * mod_inv(2)) % mod;
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