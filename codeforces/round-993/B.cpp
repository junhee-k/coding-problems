#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
    string a;
    cin >> a;
    reverse(a.begin(), a.end());
    for (char c : a){
        if(c=='q') cout << 'p';
        else if(c=='p') cout << 'q';
        else cout << c;
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}