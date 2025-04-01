#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    if(k == 0) {
        cout << 0 << endl;
        return;
    }
    
    unordered_map<int, int> f;
    int count = 0;
    
    int left = 0;
    for(int right = 0; right < n; right++) {
        f[arr[right]]++;
        
        while(f.size() > k) {
            f[arr[left]]--;
            
            if(f[arr[left]] == 0) {
                f.erase(arr[left]);
            }
            
            left++;
        }
        
        count += right-left+1;
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