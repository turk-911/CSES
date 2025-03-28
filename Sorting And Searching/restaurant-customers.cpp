#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> arrivals;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        arrivals.push_back({a, 1});
        arrivals.push_back({b, -1});
    }
    
    sort(arrivals.begin(), arrivals.end(), [](pair<int, int> a, pair<int, int> b) {
        if(a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });
    
    int curr = 0;
    int ans = 0;
    
    for(auto [t, ty]: arrivals) {
        curr += ty;
        ans = max(ans, curr);
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