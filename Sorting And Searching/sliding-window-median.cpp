#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
class util {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    unordered_map<int, int> delayed;
    
    int balance = 0;
    
    template <typename T, typename Compare>
    void remove_outdated(priority_queue<T, vector<T>, Compare> &heap) {
        while(!heap.empty() && delayed[heap.top()]) {
            delayed[heap.top()]--;
            heap.pop();
        }
    }
    
    void rebalance() {
        if(balance > 1) {
            right.push(left.top());
            left.pop();
            balance -= 2;
            remove_outdated(left);
        }
        else if(balance < 0) {
            left.push(right.top());
            right.pop();
            balance += 2;
            remove_outdated(right);
        }
    }
    
    public:
    void insert(int num) {
        if(left.empty() || num <= left.top()) {
            left.push(num);
            balance++;
        }
        else {
            right.push(num);
            balance--;
        }
        rebalance();
    }
    
    void erase(int num) {
        delayed[num]++; 
        if (num <= left.top()) {
            balance--;
            if (num == left.top()) {
                remove_outdated(left);
            }
        } 
        else {
            balance++;
            if (num == right.top()) {
                remove_outdated(right);
            }
        }
        rebalance();
    }
    
    double get_median() {
        return left.top();
    }
};
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    
    vector<int> result;
    util window;
    
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        window.insert(nums[i]);     
        if(i >= k-1) {
            double med = window.get_median();
            result.push_back(med);
            window.erase(nums[i-k+1]);
        }
    }
    
    int rs = result.size();
    for(int i = 0; i < rs; i++) {
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