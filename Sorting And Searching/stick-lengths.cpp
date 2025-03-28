#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    int n;
    cin >> n;
    
    vector<int> sticks(n);
    for(int i = 0; i < n; i++) {
        cin >> sticks[i];
    }
    
    sort(sticks.begin(), sticks.end());
    
    int length;
    
    if(n % 2 == 0) {
        int f = sticks[n/2];
        int s = sticks[n/2-1];
        length = (f+s) >> 1;
    }
    
    else {
        length = sticks[n/2];
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += abs(sticks[i]-length);
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