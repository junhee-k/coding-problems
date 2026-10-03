n = int(input())
A = list(map(int, input().split()))

# Please write your code here.
min_dist = 1000000
for i in range(n):
    dist = 0
    for j in range(len(A)):
        dist += abs(i - j) * A[j]
    min_dist = min(min_dist,dist)

print(min_dist)