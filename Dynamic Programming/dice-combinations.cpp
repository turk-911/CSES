#include <bits/stdc++.h>
#include<set>
#include<queue>
#define int long long int
#define vi vector<int>
#define pii pair<int, int>
#define vvi vector<vi>
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
int nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || n == r) return 1;
    double res = 0;
    for (int i = 0; i < r; i++) res += log(n - i) - log(i + 1);
    return (int)round(exp(res));
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
    vi arr(6);
    for(int i = 0; i < 6; i++) arr[i] = i + 1;
    int n; cin >> n;
    vector<unsigned int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 6; j++) {
            if(i - j >= 0) {
                dp[i] += dp[i - j];
                dp[i] %= mod;   
            }
        }
    }
    cout << dp[n] % mod << endl;
}
int32_t main() {
    int t = 1;
    // cin >> t;
    // precalc();
    for (int i = 1; i <= t; i++) solve();
    return 0;
}