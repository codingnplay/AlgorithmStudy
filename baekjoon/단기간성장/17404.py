import sys

N = int(sys.stdin.readline())

cost = []

for _ in range(N):
    cost.append(sys.stdin.readline().strip().split(' '))
    for i in range(len(cost[_])):
        cost[_][i] = int(cost[_][i])

minans = 2000000
for x in range(3):
    DP = [[0 for _ in range(3)] for __ in range(N)]
    for j in range(3):
        DP[0][j] = cost[0][j]
    for i in range(1, N):
        for j in range(3):
            if i == 1:
                if j == x:
                    DP[i][j] = 2000000
                else:
                    DP[i][j] = DP[0][x] + cost[i][j]
                continue

            if i == N - 1:
                if j == x:
                    DP[i][j] = 2000000
                    continue

            if j == 0:
                if DP[i-1][1] < DP[i-1][2]:
                    DP[i][0] = DP[i-1][1] + cost[i][0]
                else:
                    DP[i][0] = DP[i-1][2] + cost[i][0]
            elif j == 1:
                if DP[i-1][0] < DP[i-1][2]:
                    DP[i][1] = DP[i-1][0] + cost[i][1]
                else:
                    DP[i][1] = DP[i-1][2] + cost[i][1]
            else:
                if DP[i-1][0] < DP[i-1][1]:
                    DP[i][2] = DP[i-1][0] + cost[i][2]
                else:
                    DP[i][2] = DP[i-1][1] + cost[i][2]

    for i in range(3):
        if DP[N-1][i] < minans:
            minans = DP[N-1][i]

print(minans)
