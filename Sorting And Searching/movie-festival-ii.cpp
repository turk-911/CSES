#include <bits/stdc++.h>
#define int long long int
using namespace std;
int mod = 1000000007;
struct Movie {
    int start;
    int end;
};
bool comp(Movie a, Movie b) {
    return a.end < b.end;
}
void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<Movie> movies(n);
    for(int i = 0; i < n; i++) {
        cin >> movies[i].start >> movies[i].end;
    }
    
    sort(movies.begin(), movies.end(), comp);
    multiset<int> end_times;
    
    for(int i = 0; i < k; i++) {
        end_times.insert(0);
    }
    
    int count = 0;
    
    for(auto movie: movies) {
        auto it = end_times.upper_bound(movie.start);
        if(it == end_times.begin()) {
            continue;
        }
        
        it--;
        end_times.erase(it);
        end_times.insert(movie.end);
        count++;
    }
    
    cout << count << endl;
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