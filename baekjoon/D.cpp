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
    string mole;
    cin >> mole;
    int h_count = 0;
    int o_count = 0;

    if(n % 3 != 0)
    {
        cout << "mix";
        return 0;
    }

    if(mole[0]=='O' || mole[n-1] == 'O')
    {
        cout << "mix";
        return 0;
    } 

    for(int i = 0; i < n; i++){
        if(mole[i] == 'H') h_count++;
        else if(mole[i] == 'O') o_count++;
        if(i > 0 && mole[i] == 'O' && mole[i-1] == 'O')
        {
            cout << "mix";
            return 0;
        }
    }
    if(h_count == o_count * 2) cout << "pure";
    else cout << "mix";
}