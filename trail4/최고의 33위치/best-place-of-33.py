n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
max_count = 0
for i in range(n-2):
    for j in range(n-2):
        count = 0
        for k in range(i,i+3):
            for l in range(j,j+3):
                if grid[k][l] == 1:
                    count += 1
        max_count = max(max_count, count)

print(max_count)