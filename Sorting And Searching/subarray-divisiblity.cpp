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
    
    map<int, int> remainders;
    remainders[0] = 1;
    
    int count = 0;
    int prefix = 0;
    
    for(int i = 0; i < n; i++) {
        prefix += arr[i];
        int rem = prefix % n;
        
        if(rem < 0) {
            rem += n;
        }
        
        count += remainders[rem];
        remainders[rem]++;
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