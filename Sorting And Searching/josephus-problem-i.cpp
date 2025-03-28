#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    int n;
    cin >> n;
    
    list<int> l;
    for(int i = 1; i <= n; i++) {
        l.push_back(i);
    }
    
    auto it = l.begin();
    while(!l.empty()) {
        if(l.size() == 1) {
            cout << *it << " ";
            break;
        }
        
        it++;
        if(it == l.end()) {
            it = l.begin();
        }
        
        auto to_rem = it++;
        if(it == l.end()) {
            it = l.begin();
        }
        
        cout << *to_rem << " ";
        l.erase(to_rem);
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