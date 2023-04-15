import sys
sys.setrecursionlimit(10**6)

n, m = list(map(int, input().split()))
g = [[] for i in range(n)]

for i in range(m):
    v1,v2 = list(map(int, input().split()))
    v1 -= 1; v2 -= 1
    g[v1].append(v2)

dp = {}

# Aim: To find the longest path from one vertex to another
def dfs(j):
    global dp, g
    temp = 0
    # Check if longest path already visited from this vertex
    if dp.get(j, -1) == -1:
        # For each vertex, find maximum vertices path using DFS
        for nv in g[j]:
            temp = max(temp, 1+dfs(nv))
        dp[j] = temp
        return temp
    else:
        return dp.get(j, -1)

res = 0 
# Iterate through each vertex, and find longest path from each vertex
for i in range(n):
    res = max(res, dfs(i))

print (res)