n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
ans = 0
shapes = [
    [[1, 1, 0],
    [1, 0, 0],
    [0, 0, 0]],

    [[1, 1, 0],
    [0, 1, 0],
    [0, 0, 0]],

    [[1, 0, 0],
    [1, 1, 0],
    [0, 0, 0]],
    
    [[0, 1, 0],
    [1, 1, 0],
    [0, 0, 0]],
    
    [[1, 1, 1],
    [0, 0, 0],
    [0, 0, 0]],

    [[1, 0, 0],
    [1, 0, 0],
    [1, 0, 0]],    
]

def get_max_sum(x,y):
    max_sum = 0
    for s in range(6):
        is_possible = True
        sum_of_nums = 0
        for i in range(3):
            for j in range(3):
                if shapes[s][i][j] == 0:
                    continue
                if x + i >= n or y + j >= m:
                    is_possible = False
                else:
                    sum_of_nums += grid[x + i][y + j]
        
        if is_possible:
            max_sum = max(max_sum, sum_of_nums)

    return max_sum

for i in range(n):
    for j in range(m):
        ans = max(ans, get_max_sum(i,j))

print(ans)