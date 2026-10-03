N = int(input())
A = list(map(int, input().split()))

# Please write your code here.
sum = 0
for i in range(N):
    for j in range(i+1,N):
        if (A[i] <= A[j]):
            for k in range(j+1,N):
                if (A[j] <= A[k]): sum += 1

print(sum)