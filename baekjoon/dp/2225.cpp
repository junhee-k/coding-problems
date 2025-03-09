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

/*
Another dp problem. https://www.acmicpc.net/problem/2225

Solved this with a 2D dp array where the rows represent
the number of integers added and the columns is the target
value. This algorithm works because if we add one more
integer, we can make the value based on the number of ways
to sum the k-1 integers. I will give an example in terms 
of n,k = 2,2. for k = 1, there is simply one integer.
Then, for k=2, you add (# of ways to make 0 with 1 integer 
+ 2), (# of ways to make 1 with 1 integer + 1), and (# 
of ways to make 2 with 1 integer + 0). There is always a
pair for each previous number. Therefore, we just add up
the previous cases, giving the answer.

Side note: I got a lot of compile errors and incorrect
submissions because I didn't think of the long type and
did not notice that we had to give the answer in mod 10^9
because of integer overflow. So watch out for that next time. 
*/