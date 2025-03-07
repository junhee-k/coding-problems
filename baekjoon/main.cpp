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

