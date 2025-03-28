#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    int n;
    cin >> n;
    
    vector<int> playlist(n);
    for(int i = 0; i < n; i++) {
        cin >> playlist[i];
    }
    
    map<int, int> seen;
    int l = 0;
    int ans = 0;
    
    for(int r = 0; r < n; r++) {
        if (seen.count(playlist[r]) && seen[playlist[r]] >= l) {
            l = seen[playlist[r]]+1;
        }
        seen[playlist[r]] = r;
        ans = max(ans, r-l+1);
    }
    
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