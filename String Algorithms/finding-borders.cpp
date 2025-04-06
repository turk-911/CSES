#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    string s;
    cin >> s;
    
    int n = s.length();
    vector<int> lps(n, 0);
    
    for(int i = 1; i < n; i++) {
        int j = lps[i-1];
        while(j > 0 && s[i] != s[j]) {
            j = lps[j-1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        lps[i] = j;
    }
    
    vector<int> ans;
    int k = lps[n-1];
    
    while(k > 0) {
        ans.push_back(k);
        k = lps[k-1];
    }
    
    sort(ans.begin(), ans.end());
    for(int x: ans) {
        cout << x << " ";
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
    for (int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}