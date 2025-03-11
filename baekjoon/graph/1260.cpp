#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10001
#define INF 987654321

int n, m;
int s;
vector<int> vertex[MAX];
bool visited_dfs[1001] = {false};
bool visited_bfs[1001] = {false};

void DFS(int v) {
    visited_dfs[v] = true; // marks visited vertex as true
    cout << v << ' ';
    for (int i = 0; i < vertex[v].size(); i++) { // loops through connected vertices
        int u = vertex[v][i];
        // vertex is not visited? then recursively perform DFS until end is reached
        if(visited_dfs[u] == false) DFS(u); 
    }
}

void BFS(int s) {
    visited_bfs[s] = true;
    queue<int> q;
    q.push(s);

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for (int i = 0; i < vertex[x].size(); i++) {
            int u = vertex[x][i];
            if (visited_bfs[u] == false) {
                q.push(u); // pushes every neighbor into the queue
                visited_bfs[u] = true; // marks vertex as visited
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vertex[a].push_back(b);
        vertex[b].push_back(a); // because it is an undirected graph
    }

    for (int i = 1; i <= n; i++) {
        // sort the vertices in order to match output
        sort(vertex[i].begin(), vertex[i].end());
    }

    DFS(s);
    cout << '\n';
    BFS(s);
}