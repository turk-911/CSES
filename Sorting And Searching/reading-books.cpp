#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    sort(arr.rbegin(), arr.rend());
    int time1 = 0;
    int time2 = 0;
    
    for(int i = 0; i < n; i++) {
        if(time1 <= time2) {
            time1 += arr[i];
        }
        else {
            time2 += arr[i];
        }
    }
    
    int ans = max(time1, time2);
    
    cout << ans+ans << endl;
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