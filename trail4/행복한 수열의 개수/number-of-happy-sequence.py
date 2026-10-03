n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
seq = [0 for _ in range(n)]

def is_happy_sequence():
    consecutive_count, max_ccnt = 1, 1
    for i in range(1, n):
        if seq[i-1] == seq[i]:
            consecutive_count += 1
        else:
            consecutive_count = 1
        max_ccnt = max(max_ccnt, consecutive_count)

    return max_ccnt >= m

happy = 0

for i in range(n):
    seq = grid[i][:]

    if is_happy_sequence():
        happy += 1

for j in range(n):
    for i in range(n):
        seq[i] = grid[i][j]

    if is_happy_sequence():
        happy += 1

print(happy)