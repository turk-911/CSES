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
int resolve(int pos, bool tight, int last, vector<int> &digits, vector<vector<vector<int>>> &dp) {
    int ds = digits.size();
    if(pos == ds) {
        return 1;
    }
    
    if(dp[pos][tight][last] != -1) {
        return dp[pos][tight][last];
    }
    
    int limit = tight ? digits[pos] : 9;
    int ans = 0;
    
    for(int d = 0; d <= limit; d++) {
        if(d != last || last == 10) {
            ans += resolve(pos+1, tight && (d == limit), d, digits, dp);
        }
    }
    
    return dp[pos][tight][last] = ans;
}
int count(int num) {
    if(num < 0) {
        return 0;
    }

    vector<int> digits;
    while(num) {
        digits.push_back(num%10);
        num /= 10;
    }

    reverse(digits.begin(), digits.end());
    int ds = digits.size();
    
    vector<vector<vector<int>>> dp(ds, vector<vector<int>>(2, vector<int>(11, -1)));
    return resolve(0, 1, 10, digits, dp);
}
void solve() {
    int a, b;
    cin >> a >> b;

    int bb = count(b);
    int aa = count(a-1);

    cout << bb-aa << endl;
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