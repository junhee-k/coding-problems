#https://www.acmicpc.net/problem/1655
import heapq
import sys

input = sys.stdin.readline

n = int(input())
leftheap, rightheap = [], []

for _ in range(n):
    num = int(input())
    if len(leftheap) == len(rightheap):
        heapq.heappush(leftheap,-num)
    else:
        heapq.heappush(rightheap,num)

    if leftheap and rightheap and rightheap[0] < leftheap[0] * -1:
        min_right = heapq.heappop(rightheap)
        max_left = -heapq.heappop(leftheap)

        heapq.heappush(leftheap, -min_right)
        heapq.heappush(rightheap, max_left)

    print(-leftheap[0])