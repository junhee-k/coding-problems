#https://www.acmicpc.net/problem/5073
while True:
    sides = list(map(int, input().split()))

    if(0 == sides[0] and 0 == sides[1] and 0 == sides[2]):
        break

    sides.sort()
    if(sides[0]+sides[1]<=sides[2]):
        print("Invalid")
    elif(sides[0]==sides[1]):
        if(sides[1]==sides[2]):
            print("Equilateral")
        else:
            print("Isosceles")
    elif(sides[1]==sides[2]):
       print("Isosceles")
    else:
        print("Scalene") 