#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int coins[n];
    int dp[k+1];
    fill(coins, coins + n, 0);
    fill(dp, dp + k + 1, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j <= k; j++) {
            dp[j] += dp[j-coins[i]];
        }
    }
    cout << dp[k] << '\n';
}

/*
Solved with dp.

Using a simple example to explain, lets say we need to find 
the number of ways to make the $5 with coins $1, $2, $3. We first
find the number of ways to make each number up to $5 with $1 coins.
For $i, it always continues from the previous case $i-1. 
In code, this is equivalent to dp[i] += dp[i-1]. dp[0] = 1 
because there is one way to make $0: add no coins. Then we consider adding
$2 coins to all values up to $5. This would need to reference the different
ways we added using only $1 coins as well. Therefore, dp[i] += dp[i-2].
Finally, we do the same for $3 coins. This recursive pattern ensures that
we find all the different combinations, without duplicates (ex. $2+$1, and $1+$2),
since we figured out all possible outcomes for $1 before moving on to $2. Following
this dynamic programming pattern, we can get the desired output at dp[5] = 5.
*/