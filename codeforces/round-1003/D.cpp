#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, m, num;
    cin >> n >> m;
    vector<pair<int,int>> pairs(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> num;
            cout << "num is: " << num << '\n';
            pairs[i].first += num;
            pairs[i].second += pairs[i].second + num;
            cout << "sum is: " << pairs[i].first << '\n';
            cout << "score is: " << pairs[i].second << '\n';
        }
    }
    sort(pairs.begin(), pairs.end(), greater<>());
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += pairs[i].second;
        for(int j = 0; j <= i; j++){
            ans += pairs[i].first;
        }
    }
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}