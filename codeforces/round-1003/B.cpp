#include <iostream>
using namespace std;

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length() - 1; i++){
        if(s[i]==s[i+1]){
            cout << 1 << '\n';
            return;
        }
    }
    cout << s.length() << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}