#include <iostream>
using namespace std;

void solve() {
    string w;
    cin >> w;
    cout << w.substr(0,w.length()-2) << 'i' << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}