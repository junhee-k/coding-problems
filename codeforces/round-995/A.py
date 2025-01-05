# https://codeforces.com/contest/2051/problem/A
for _ in range(int(input())):
    n = int(input())
    m = list(map(int,input().split()))
    s = list(map(int,input().split()))
    s.append(0)
    result = 0
    for i in range(n):
        if m[i] > s[i+1]:
            result += m[i]-s[i+1]
    print(result)
