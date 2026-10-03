R, C = map(int, input().split())
grid = [list(input().split()) for _ in range(R)]

# Please write your code here.
cnt = 0
for i in range(1,R-1):
    for j in range(1,C-1):
        if grid[0][0] != grid[i][j]:
            for k in range(i+1,R):
                for l in range(j+1,C):
                    if (grid[i][j] != grid[k][l] and k < R - 1 and l < C - 1 and grid[k][l] != grid[R-1][C-1]):
                        cnt += 1
print(cnt)