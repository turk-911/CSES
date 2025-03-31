#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    int n, x;
    cin >> n >> x;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    unordered_map<int, int> prefix_count;
    prefix_count[0] = 1;
    
    int prefix_sum = 0;
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];
        
        if(prefix_count.find(prefix_sum-x) != prefix_count.end()) {
            count += prefix_count[prefix_sum-x];
        }
        
        prefix_count[prefix_sum]++;
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