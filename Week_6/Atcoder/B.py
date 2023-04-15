from math import inf
n, k = list(map(int, input().split()))
arr = list(map(int, input().split()))
dp = [inf for k in range(n)]
dp[0] = 0
for i in range(n):
    end = i+k+1
    if end > n:
        end = n
    # print (i, end)
    for j in range(i+1, end):
        dp[j] = min(dp[j], dp[i]+abs(arr[i]-arr[j]))
print (dp[-1])