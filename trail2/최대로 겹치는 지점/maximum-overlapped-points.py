n = int(input())
segments = [tuple(map(int, input().split())) for _ in range(n)]

# Please write your code here.
count = [0] * 101

for s in segments:
    for i in range(s[0],s[1]+1):
        count[i] += 1

print(max(count))