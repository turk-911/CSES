#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
void solve() {
    int n, x;
    cin >> n >> x;
    
    vector<pair<int, int>> arr(n);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i < n-2; i++) {
        if(i == 0 || (i > 0 && arr[i].first != arr[i-1].first)) {
            int low = i+1;
            int high = n-1;
            
            int target = x-arr[i].first;
            while(low < high) {
                if(arr[low].first+arr[high].first == target) {
                    cout << arr[i].second << " " << arr[low].second << " " << arr[high].second << endl;
                    return;
                } 
                else if(arr[low].first+arr[high].first < target) {
                    low++;
                }
                else {
                    high--;
                }
            } 
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
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