#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> desired_size(n);
    for(int i = 0; i < n; i++) {
        cin >> desired_size[i];
    }
    
    vector<int> size(m);
    for(int i = 0; i < m; i++) {
        cin >> size[i];
    }
    
    sort(desired_size.begin(), desired_size.end());
    sort(size.begin(), size.end());
    
    int i = 0;
    int j = 0;
    int ans = 0;
    
    while(i < n && j < m) {
        if(abs(desired_size[i]-size[j]) <= k) {
            ans++;
            i++;
            j++;
        }
        else if(size[j] < desired_size[i]-k) {
            j++;
        }
        else {
            i++;
        }
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