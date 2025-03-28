#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    int n, m;
    cin >> n >> m;
    
    multiset<int> ms;
    for(int i = 0; i < n; i++) {
        int ticket;
        cin >> ticket;
        
        ms.insert(ticket);
    }
    
    for(int i = 0; i < m; i++) {
        int offer;
        cin >> offer;
        
        auto it = ms.upper_bound(offer);
        if(it == ms.begin()) {
            cout << -1 << endl;
        }
        else {
            it--;
            cout << *it << endl;
            ms.erase(it);
        }
    }
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