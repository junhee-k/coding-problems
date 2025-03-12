#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 101
#define INF 987654321

int v, e;
vector<int> vertex[MAX];
int cnt = 0;
bool visited_bfs[MAX] = {false};

int BFS(int s) {
    visited_bfs[s] = true;
    queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < vertex[x].size(); i++) {
            int u = vertex[x][i];
            if (visited_bfs[u] == false) {
                q.push(u); // pushes every neighbor into the queue
                visited_bfs[u] = true; // marks vertex as visited
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    cin >> v;
    cin >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        vertex[a].push_back(b);
        vertex[b].push_back(a); // because it is an undirected graph
    }
    BFS(1);
    cout << cnt;
    return 0;
}