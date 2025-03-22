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
void solve() {
    string s;
    cin >> s;
    
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i <= n-len; i++) {
            int j = i+len-1;
            if(s[i] == s[j]) {
                dp[i][j] = 2+dp[i+1][j-1];
            }
            else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    
    int i = 0;
    int j = n-1;
    string ans;
    
    while(i <= j) {
        if(s[i] == s[j]) {
            ans += s[i];
            i++;
            j--;
        }
        else if(dp[i+1][j] > dp[i][j-1]) {
            i++;
        }
        else {
            j--;
        }
    }
    
    string rev = ans;
    reverse(rev.begin(), rev.end());
    if(dp[0][n-1] % 2 != 0) {
        rev = rev.substr(1, rev.length());
    }
    
    // ans += rev;
    cout << ans+rev << endl;
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