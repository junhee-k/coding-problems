n = int(input())
x = []
dir = []
for _ in range(n):
    xi, di = input().split()
    x.append(int(xi))
    dir.append(di)

# Please write your code here.
count = [0] * 2001
off = 1000
ptr = 0
nptr = 0

for i in range(n):
    if dir[i] == 'R':
        nptr = ptr + x[i]
        for j in range(ptr, nptr):
            count[off + j] += 1
    else:
        nptr = ptr - x[i]
        for j in range(nptr, ptr):
            count[off + j] += 1
    
    ptr = nptr
    #print(list(range(-15,16)))
    #print(count[off-15:off+16])

ans = 0

for e in count:
    if e > 1:
        ans += 1

print(ans)