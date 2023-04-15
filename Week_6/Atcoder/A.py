from math import inf
import sys
sys.setrecursionlimit(100000)
n = int(input())
arr = list(map(int, input().split()))
# Bottom up method
# dp = [inf for i in range(n)]
# dp[0] = 0
# for i in range(n):
#     if i+1 < n:
#         dp[i+1] = min(dp[i+1], dp[i]+abs(arr[i]-arr[i+1]))
#     if i+2 < n:
#         dp[i+2] = min(dp[i+2], dp[i]+abs(arr[i]-arr[i+2]))
# print (dp[-1])

# Top down method
# dp = [-1 for i in range(n)]
# def r_func(ind):
#     global dp
#     global arr
#     # Base case
#     if ind == (n-1): return 0
#     if ind >= n: return inf
#     if (dp[ind] != -1): return dp[ind]
#     # Checking ind+1 height
#     left = abs(arr[ind]-arr[ind+1]) + r_func(ind+1)
#     right = inf
#     # Checking ind+2 height
#     if (ind+2) < n:
#         right = abs(arr[ind]-arr[ind+2]) + r_func(ind+2)
#     # Minimizing value at current index
#     dp[ind] = min(left, right)
#     return (dp[ind])
# print (r_func(0))