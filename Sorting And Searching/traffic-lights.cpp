#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    int x, n;
    cin >> x >> n;
    
    set<int> lights;
    multiset<int> segments;
    
    lights.insert(0);
    lights.insert(x);
    segments.insert(x);
    
    for(int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        
        auto it = lights.upper_bound(pos);
        int right = *it;
        int left = *prev(it);
        
        segments.erase(segments.find(right-left));
        
        segments.insert(pos-left);
        segments.insert(right-pos);
        
        lights.insert(pos);
        
        cout << (*segments.rbegin()) << " ";
    }
    
    cout << endl;
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