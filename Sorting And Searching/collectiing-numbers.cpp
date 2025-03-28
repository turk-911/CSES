#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    int n;
    cin >> n;
    
    vector<int> pos(n+1, 0);
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        
        pos[x] = i;
    }
    
    int rounds = 1;
    for(int i = 1; i < n; i++) {
        if(pos[i] > pos[i+1]) {
            rounds++;
        }
    }
    
    cout << rounds << endl;
    
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