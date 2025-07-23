#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    auto calc = [&](vector<int> &a) {
        sort(a.begin(), a.end());
        __int128 pref = 0;
        __int128 tot = 0;
        for(int i = 0; i < n; i++) {
            tot += a[i] * i - pref;
            pref += a[i];
        }
        return tot;
    };
    __int128 total = calc(x)+calc(y);
    string ans = "";
    if(total == 0) {
        cout << 0 << endl;
        return;
    }
    bool neg = total < 0;
    if(neg) {
        total = -total;
    }
    while(total > 0) {
        ans.push_back('0'+ total%10);
        total /= 10;
    }
    if(neg) {
        ans.push_back('-');
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
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