#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    int n, x;
    cin >> n >> x;
    
    vector<int> weights(n);
    for(int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    sort(weights.begin(), weights.end());
    
    int i = 0;
    int j = n-1;
    int ans = 0;
    
    while(i <= j) {
        if(weights[i]+weights[j] <= x) {
            i++;
        }
        j--;
        ans++;
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