#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    int n;
    cin >> n;
    
    vector<int> coins(n);
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    sort(coins.begin(), coins.end());
    
    int ans = 1;
    for(int i = 0; i < n; i++) {
        int coin = coins[i];
        if(coin > ans) {
            break;
        }
        ans += coin;
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