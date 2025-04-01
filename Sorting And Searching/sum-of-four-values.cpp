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
    
    for(int i = 0; i < n-3; i++) {
        if(i && arr[i].first == arr[i-1].first) {
            continue;
        }
        int a = arr[i].first;
        
        for(int j = i+1; j < n-2; j++) {
            if(j != i+1 && arr[j].first == arr[j-1].first) {
                continue;
            }
            
            int low = j+1;
            int high = n-1;
            
            while(low < high) {
                int sum = a+arr[j].first+arr[low].first+arr[high].first;
                if(sum == x) {
                    cout << arr[i].second << " " << arr[j].second << " " << arr[low].second << " " << arr[high].second << endl;
                    return;
                }
                else if(sum < x) {
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