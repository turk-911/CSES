#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
struct Range {
    int a, b, index;
};
void solve() {
    int n;
    cin >> n;
    
    vector<Range> ranges(n);
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        ranges[i].a = a;
        ranges[i].b = b;
        ranges[i].index = i;
    }
    
    sort(ranges.begin(), ranges.end(), [&](const Range &r1, const Range &r2) {
        if(r1.a == r2.a) {
            return r1.b > r2.b;
        }
        return r1.a < r2.a;
    });
    
    vector<bool> contains(n, 0);
    vector<bool> contained(n, 0);
    
    int max_b = -1;
    for(int i = 0; i < n; i++) {
        if(ranges[i].b <= max_b) {
            contained[ranges[i].index] = 1;
        }
        max_b = max(max_b, ranges[i].b);
    }
    
    int min_b = 1e10;
    for(int i = n-1; i >= 0; i--) {
        if(ranges[i].b >= min_b) {
            contains[ranges[i].index] = 1;
        }
        min_b = min(min_b, ranges[i].b);
    }
    
    for(int i = 0; i < n; i++) {
        cout << contains[i] << " ";
    }
    cout << endl;
    
    for(int i = 0; i < n; i++) {
        cout << contained[i] << " ";
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