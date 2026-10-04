n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
max_sum = 0
for i in range(n):
    for j in range(m-2):
        sum = grid[i][j] + grid[i][j+1] + grid[i][j+2]
        max_sum = max(max_sum, sum)

for i in range(n-2):
    for j in range(m):
        sum = grid[i][j] + grid[i+1][j] + grid[i+2][j]
        max_sum = max(max_sum, sum)

for i in range(n-1):
    for j in range(m-1):
        sum = grid[i][j] + grid[i+1][j] + grid[i][j+1] + grid[i+1][j+1]
        min_sq = min(grid[i][j], grid[i+1][j], grid[i][j+1], grid[i+1][j+1])
        sum = sum - min_sq
        #print(i,j,sum)
        max_sum = max(max_sum, sum)

print(max_sum)