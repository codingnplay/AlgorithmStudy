import heapq
import sys

minheap = []
maxheap = []

N = int(sys.stdin.readline())

for i in range(N):
	x = int(sys.stdin.readline())
	if len(minheap) == len(maxheap):
		heapq.heappush(maxheap, -x)
	else:
		heapq.heappush(minheap, x)

	if minheap and minheap[0] < -maxheap[0]:
		l = heapq.heappop(minheap)
		r = -heapq.heappop(maxheap)
		heapq.heappush(minheap, r)
		heapq.heappush(maxheap, -l)

	print(-maxheap[0])
