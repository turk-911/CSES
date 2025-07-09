#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    string s;
    cin >> s;
    if(s.empty()) {
        cout << s << endl;
        return;
    }
    string t = "^";
    for(char ch : s) {
        t += "#" + string(1, ch);
    }
    t += "#$";
    int n = t.length();
    vector<int> p(n, 0);
    int center = 0;
    int maxLen = 0;
    int right = 0;
    int maxCenter = 0;
    for(int i = 1; i < n - 1; i++) {
        int mirror = 2 * center - i;
        if(i < right) {
            p[i] = min(right - i, p[mirror]);
        }
        while(t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
            p[i]++;
        }
        if(i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
        if(p[i] > maxLen) {
            maxLen = p[i];
            maxCenter = i;
        }
    }
    int start = (maxCenter - maxLen) / 2;
    cout << s.substr(start, maxLen) << endl;
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