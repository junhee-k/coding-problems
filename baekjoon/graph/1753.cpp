#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 20001
#define INF 987654321

int v, e;
int s;
int dist[MAX];
vector<pair<int, int>> vertex[MAX];

int main() {
    cin >> v >> e;
    cin >> s;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vertex[a].push_back(make_pair(b, c));
    }
    for (int i = 1; i <= v; i++) dist[i] = INF;

    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,s));
    dist[s] = 0;

    while (!pq.empty()) {
        int distance = -pq.top().first;
        int current = pq.top().second;

        pq.pop();

        if (dist[current] < distance) continue;

        for (int i = 0; i < vertex[current].size(); i++) {
            int next = vertex[current][i].first;
            int next_distance = distance + vertex[current][i].second;

            if (next_distance < dist[next]) {
                dist[next] = next_distance;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}