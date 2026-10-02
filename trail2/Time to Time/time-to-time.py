a, b, c, d = map(int, input().split())

# Please write your code here.
mins = 0
if b > d:
    a += 1
    mins += 60-b
    mins += 60*(c-a)
    mins += d
else:
    mins += 60*(c-a)
    mins += d-b

print(mins)