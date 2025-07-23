#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int count = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<int, int> mp;
    int l = 0;
    for(int r = 0; r < n; r++) {
        if(mp.count(arr[r]) && mp[arr[r]] >= l) {
            l = mp[arr[r]]+1;
        }
        mp[arr[r]] = r;
        count += (r-l+1);
    }
    cout << count << endl;
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