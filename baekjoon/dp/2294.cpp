#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int coins[n];
    int dp[k+1];
    fill(coins, coins + n, 0);
    fill(dp, dp + k + 1, 10001);
    
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= k; j++) {
            dp[j] = min(1 + dp[j-coins[i]], dp[j]);
        }
    }
    if(dp[k]==10001) cout << -1 << '\n';
    else cout << dp[k] << '\n';
}

/*
Similar problem to 2293. Except this time it looks for the least
number of coins required to reach the number. Points to look out 
for future problems is to utilize the max value to find min and 
check if there are any possibilities that a certain entry will 
not be filled in the algorithm's process.
*/