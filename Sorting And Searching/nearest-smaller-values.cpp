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
    
    stack<int> st;
    st.push(1);
    
    vector<int> result(n, 0);
    
    for(int i = 1; i < n; i++) {
        while(!st.empty() && arr[st.top()-1] >= arr[i]) {
            st.pop();
        }
        if(!st.empty()) {
            result[i] = st.top();
        } 
        st.push(i+1);
    }
    
    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
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