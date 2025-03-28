#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    
    int index = 0;
    while(!v.empty()) {
        index = (index+k) % v.size();
        cout << v[index] << " ";
        v.erase(v.begin()+index);
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
};