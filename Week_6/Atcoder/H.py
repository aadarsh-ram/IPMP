import sys
sys.setrecursionlimit(10**6)
MOD = 10**9 + 7
h, w = list(map(int, input().split()))
arr = []
for i in range(h):
    arr.append(list(input()))

dp = [[-1 for i in range(w)] for j in range(h)]

# Top down approach
# Aim: To find all paths leading to (h,w), by moving down or right
no_paths = 0
def ans(i,j):
    global no_paths
    # When hitting block, no path possible
    if arr[i][j] == '#':
        return 0
    # Comes to final pos, path possible
    if i == h-1 and j == w-1:
        no_paths += 1
        return 1
    # Stores all possible paths from that position
    if dp[i][j] != -1:
        no_paths += dp[i][j]%MOD
        return dp[i][j]
    if i != h-1 and j != w-1:
        # Stores the addition of all possible paths from going below and right
        dp[i][j] = ans(i,j+1)+ans(i+1,j)
        return dp[i][j]
    # If position reaches bottom, recurs to the right
    if i == h-1 and j != w-1:
        dp[i][j] = ans(i,j+1)
        return dp[i][j]
    # If position reaches right end, recurs below
    if i != h-1 and j == w-1:
        dp[i][j] = ans(i+1,j)
        return dp[i][j]

ans(0,0)
# print (dp)
print(no_paths%MOD)