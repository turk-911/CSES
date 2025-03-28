#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    int n;
    cin >> n;
    
    vector<int> cubes(n);
    for(int i = 0; i < n; i++) {
        cin >> cubes[i];
    }
    
    multiset<int> towers;
    for(int cube: cubes) {
        auto it = towers.upper_bound(cube);
        if(it != towers.end()) {
            towers.erase(it);
        }
        towers.insert(cube);
    }
    
    int ans = towers.size();
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