import sys

def dfs(i, j, y):

	if len(key) - 1 == y:
		memori[i][j][y] = 1
		return 1

	res = 0
	for t in range(-k, k+1):
		if t != 0:
			dx = i + t
			if 0 <= dx < n and board[dx][j] == key[y+1]:
				if memori[dx][j][y+1] != -1:
					res = res + memori[dx][j][y+1]
				else:
					res = res + dfs(dx, j, y+1)
			dy = j + t
			if 0 <= dy < m and board[i][dy] == key[y+1]:
				if memori[i][dy][y+1] != -1:
					res = res + memori[i][dy][y+1]
				else:
					res = res + dfs(i, dy, y+1)

	memori[i][j][y] = res
	return res

nmk = sys.stdin.readline().strip().split(' ')
n = int(nmk[0])
m = int(nmk[1])
k = int(nmk[2])

board = []
for _ in range(n):
	board.append(list(sys.stdin.readline().strip()))

key = list(sys.stdin.readline().strip())

#visited = [[False for j in range(m)] for i in range(n)]
memori = [[[-1 for x in range(len(key))] for j in range(m)] for i in range(n)]
ans = 0
for i in range(n):
	for j in range(m):
		if board[i][j] == key[0]:
			ans = ans + dfs(i, j, 0)
print(ans)
