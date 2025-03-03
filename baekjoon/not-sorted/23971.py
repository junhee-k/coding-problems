#https://www.acmicpc.net/problem/23971
h,w,n,m = map(int, input().split())
count = 0

for i in range(0,h,1+n):
    for j in range(0,w,1+m):
        count += 1

print(count)