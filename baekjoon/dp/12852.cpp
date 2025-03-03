#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int dp[n+1];

    dp[1] = 0;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + 1;
        if(i%3==0) dp[i] = min(dp[i],dp[i/3]+1);
        if(i%2==0) dp[i] = min(dp[i],dp[i/2]+1); 
    }
    cout << dp[n] << '\n';

    int count = n;
    cout << count << ' ';
    while(count > 1) {
        if(count % 3 == 0 && dp[count/3] == dp[count] - 1){
            cout << count/3 << ' ';
            count /= 3;
        }
        else if(count % 2 == 0 && dp[count/2] == dp[count] - 1){
            cout << count/2 << ' ';
            count /= 2;
        }
        else{
            cout << count-1 << ' ';
            count--;
        }
    }
}

/*
Same solution as 1463 except you have to be able to backtrack to find your solution. 
This could have been done by maintaining another array containing the previous indexes 
but that would require me to rewrite the solution. Also, I wanted to see if I could go backward.
*/
