#include <iostream>
using namespace std;


int n, m;
int arr[500][500];
int dp[500][500];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int DFS(int x, int y){
    if(x == n-1 && y == m-1) return 1;
    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    for (int i =0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < m){
            if(arr[nx][ny] < arr[x][y]){
                dp[x][y] = dp[x][y] + DFS(nx,ny);
            }
        }
    }
    return dp[x][y];
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }

    cout << DFS(0,0);
}

/*
This solution combines DFS with dynamic programming to
find the # of paths to the n,m index of the matrix. The
dp[i][j] value is set to represent the number of paths 
to position (n-1,m-1) from the position (i,j). If the value
is -1, it means that a path to position (n-1,m-1) has not
been computed yet. At the end of the program, any 
dp[i][j] == -1 means that the DFS algorithm did reach that
position. As the DFS traces back, it adds the number of paths
to (n-1,m-1) until 0,0. The answer of the question is stored
in dp[0][0], which is what is returned at the end.
*/