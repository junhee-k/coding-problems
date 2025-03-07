#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int asc[n];
    int desc[n];

    fill(arr, arr + n, 0);
    fill(asc, asc + n, 1);
    fill(desc, desc + n, 1);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++){
            if(arr[j] < arr[i] && asc[i] < asc[j] + 1){
                asc[i] = asc[j] + 1;
            }
        }
    }

    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j > i; j--){
            if(arr[j] < arr[i] && desc[i] < desc[j] + 1){
                desc[i] = desc[j] + 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        if(ans < asc[i] + desc[i] - 1) ans = asc[i] + desc[i] - 1;
    }

    cout << ans << '\n';
}

/*
This dp problem uses requires you to check the maximum
count for bitonic sequences. This is found by finding
both the counts for longest increasing sequence and 
longest decreasing sequences. Then, at the last step,
we add these the results for each index of the dp array
increasing and descreasing to find the maximum value.
The -1 is added for because the index number is counted
twice if we add the count for both increasing and
decreasing. Came close to finding the answer but had
to check another person's answer because i couldn't 
figure out that the second condition of the if statement.
That part is required to ensure that it the new value is
higher than another value that was found before.
*/