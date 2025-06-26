#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main() {
    int n; 
    cin >> n;
    string a,b;
    cin >> a;
    cin >> b;
    int ans = 0;

    for(int i = 0; i < 2*n; i++)
    {
        if(a[i] == b[i])
        {
            if(a[i] == 'R')
            {
                int idx = a.substr(i).find('U');
                swap(a[i],a[idx+i]);
            }
            else
            {
                int idx = a.substr(i,n-i-1).find('R');
                swap(a[i],a[i+idx]);
            }
            ans++;

            cout << a << '\n';
            cout << b << '\n';
        }
    }
    cout << ans;
}

/*
RU
UR

RURU
RRUU
0



UURR
RRUU
0

RUUR
RUUR
2

URUR
UURR
1

URUR
URUR

*/