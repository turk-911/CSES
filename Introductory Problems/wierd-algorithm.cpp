#include<iostream>
#include<vector>
#include<stack>
#include<cstdio>
#include<set>
#include<map>
#include<unordered_set>
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
void solve(int t) {
    int n;
    cin >> n;
    while(n != 1) {
        cout << n << " ";
        if(n % 2 == 0) {
            n = n / 2;
        }
        else {
            n = n * 3;
            n = n + 1;
        }
    }
    cout << 1 << endl;
}
int32_t main() {
    int t = 1;
    // cin >> t;
    // precalc();
    for (int i = 1; i <= t; i++) solve(i);
    return 0;
}