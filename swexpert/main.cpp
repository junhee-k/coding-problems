#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main() {
    int t = 10;
    
    for(int i = 1; i <= t; i++){
        int n;
        vector<int> v;
        cin >> n;
        for(int i = 0; i < n; i++){
            int input;
            cin >> input;
            v.push_back(input);
        }
        int front = 2;
        int back = n-2;
        int result = 0;

        for(int i = front; i < back; i++){
            vector<int> v1(v.begin()+i-2,v.begin()+i+3);
            v1.erase(v1.begin() + 2);
            int max_val = *max_element(v1.begin(), v1.end());
            if(max_val < v[i]) result += v[i] - max_val;
            //cout << result << " ";
            v1.clear();
        }
        cout << "#" << i << " " << result << '\n';
        v.clear();
    }
}