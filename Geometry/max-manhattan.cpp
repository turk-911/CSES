#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    int n;
    cin >> n;
    int max1 = LLONG_MIN, min1 = LLONG_MAX;
    int max2 = LLONG_MIN, min2 = LLONG_MAX;
    int max3 = LLONG_MIN, min3 = LLONG_MAX;
    int max4 = LLONG_MIN, min4 = LLONG_MAX;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        int t1 = x+y;
        int t2 = x-y;
        int t3 = -x+y;
        int t4 = -x-y;
        max1 = max(max1, t1);
        min1 = min(min1, t1);
        max2 = max(max2, t2);
        min2 = min(min2, t2);
        max3 = max(max3, t3);
        min3 = min(min3, t3);
        max4 = max(max4, t4);
        min4 = min(min4, t4);
        int ans = max({max1-min1, max2-min2, max3-min3, max4-min4});
        cout << ans << endl;
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    // precalc();
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}