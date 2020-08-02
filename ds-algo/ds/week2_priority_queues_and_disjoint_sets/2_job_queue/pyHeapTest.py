import sys
import heapq
def read(): 
    return [int(i) for i in sys.stdin.readline().strip().split()]
n, m = read()
arr = read()

q = []

for i in range(n):
    heapq.heappush(q, (0, i))

for i in range(m):
    x, y = heapq.heappop(q)
    print(y, x)
    heapq.heappush(q, (x+arr[i], y))
