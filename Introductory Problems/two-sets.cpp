#include<iostream>
#include<vector>
#include<stack>
#include<cstdio>
#include<set>
#include<map>
#include<unordered_set>
#include<cmath>
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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
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
        if(!arr[i]) {
            for(int j = i * i; j < 1000001; j += i) {
                arr[j] = true;
            }
        }
    }
    for(int i = 0; i < 1000001; i++) {
        if(!arr[i]) tPrimes.insert(i * i);
    }
}
int nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || n == r) return 1;
    double res = 0;
    for (int i = 0; i < r; i++) res += log(n - i) - log(i + 1);
    return (int)round(exp(res));
}
void solve(int t) {
    int n;
    cin >> n;
    int m = n;
    int sum = csum(n);
    if(sum & 1) {
        cout << "NO" << endl;
        return;
    }
    vb vis(n + 1, 0);
    int h = sum / 2;
    int a = 0;
    vi set1;
    while(a + n < h) {
        a += n;
        vis[n] = 1;
        set1.pb(n);
        n--;
    }
    if(a < h) {
        int diff = h - a;
        set1.pb(diff);
        vis[diff] = 1;
    }
    cout << "YES" << endl;
    int u = set1.size();
    cout << u << endl;
    for(int i = 0; i < u; i++) cout << set1[i] << " ";
    cout << endl;
    cout << m - u << endl;
    for(int i = 1; i <= m; i++) if(!vis[i]) cout << i << " ";
    cout << endl;
}
int32_t main() {
    int t = 1;
    // cin >> t;
    // precalc();
    for (int i = 1; i <= t; i++) solve(i);
    return 0;
}