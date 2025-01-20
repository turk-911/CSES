#include<iostream>
#include<algorithm>
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
    for(int i = 2; i <= a; i++) p = p * i;
    return p;
}
void solve(int t) {
    int n;
    cin >> n;
    mii count;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        count[x]++;
    }
    int a = count.size();
    cout << a << endl;
}
int32_t main() {
    int t = 1;
    // cin >> t;
    // precalc();
    for (int i = 1; i <= t; i++) solve(i);
    return 0;
}
