A = input()

# Please write your code here.
n = len(A)
ans = 0;
for i in range(n):
    if A[i] == '(':
        for j in range(i+1,n):
            if A[j] == ')':
                ans += 1

print(ans)

