#include <iostream>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    int b[m];
    for (int j = 0; j < m; j++){
        cin >> b[j];
    } 

    for(int i = 1; i < n; i++){
        if(a[i] < a[i-1]){
            if(b[0]-a[i] < a[i-1]){
                cout << "NO" << '\n';
                return;
            }
            else {
                a[i] = b[0]-a[i];
            }
        }
    }
    cout << "YES" << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}