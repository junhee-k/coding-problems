#include <iostream>
using namespace std;


int main() {
    string a,b;
    cin >> a >> b;
    int n1 = a.size();
    int n2 = b.size();
    int dp[n1+1][n2+1];

    for(int i = 0; i <= n1; i++) dp[i][0] = 0;
    for(int j = 0; j <= n2; j++) dp[0][j] = 0;
    
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                //cout << a[i-1] << ' ' << b[j-1] << '\n';
            }
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout << dp[n1][n2];
}

/*
Set up a dp table for all the possible outcomes. Then, when there
is a match, this means both pointers i and j will move + 1.
Therefore, we take the value from dp[i-1][j-1] + 1. If not a match,
we take the longer common subsequence between string a and b.
*/