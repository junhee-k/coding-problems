#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
long long dp[201][201];


int main() {
    cin >> n >> k;
    for (int j = 0; j <= n; j++){
        dp[1][j] = 1;
    }

    for (int i = 2; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= j; k++){
                dp[i][j] += dp[i-1][j-k];
            }
            dp[i][j] %= 1000000000;
        }
    }
    cout << dp[k][n];
}