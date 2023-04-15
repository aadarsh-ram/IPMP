import sys
# input = sys.stdin.readline
# print = sys.stdout.write
# Convert integer to string before using print
sys.setrecursionlimit(10**7)

s = input()
t = input()
n = len(s)
m = len(t)

dp = [[-1 for i in range(m+1)] for j in range(n+1)]
best = [[0 for i in range(m+1)] for j in range(n+1)]

# Faster top down approach
def ans(i,j):
    global dp, best, n, m
    if (i>=n) or (j>=m):
        return 0
    if dp[i][j] != -1:
        return dp[i][j]
    res = 0
    if s[i] == t[j]:
        res = 1 + ans(i+1, j+1)
        best[i][j] = 1
    else:
        if dp[i+1][j] != -1:
            val1 = dp[i+1][j]
        else:
            val1 = ans(i+1, j)
        if dp[i][j+1] != -1:
            val2 = dp[i][j+1]
        else:
            val2 = ans(i, j+1)
        res = max(val1, val2)
        if val1 > val2:
            best[i][j] = 2
        else:
            best[i][j] = 3
    dp[i][j] = res
    return res

total_ans = ''
def string_gen(i,j):
    global total_ans, best, s, t
    if (i>=n) or (j>=m):
        return
    if best[i][j] == 1:
        total_ans += s[i]
        string_gen(i+1, j+1)
    elif best[i][j] == 2:
        string_gen(i+1, j)
    elif best[i][j] == 3:
        string_gen(i, j+1)

max_len = ans(0, 0)
string_gen(0, 0)
print (total_ans)

# Top down approach
# def ans(n,m):
#     global s,t
#     if n == 0 or m == 0:
#         return ('', 0)
#     if dp[n][m] != -1:
#         return dp[n][m]
#     elif s[n-1] == t[m-1]:
#         if dp[n-1][m-1] != -1:
#             val = dp[n-1][m-1]
#         else:
#             val = ans(n-1, m-1)
#             dp[n-1][m-1] = val
#         dp[n][m] = (val[0]+s[n-1], 1+val[1])
#         return dp[n][m]
#     else:
#         if dp[n-1][m] != -1:
#             s1, val1 = dp[n-1][m]
#         else:
#             s1, val1 = ans(n-1, m)
#             dp[n-1][m] = (s1,val1)
#         if dp[n][m-1] != -1:
#             s2,val2 = dp[n][m-1]
#         else:
#             s2, val2 = ans(n, m-1)
#             dp[n][m-1] = (s2,val2)
#         if max(val1, val2) == val1:
#             dp[n][m] = (s1,val1)
#             return (s1, val1)
#         else:
#             dp[n][m] = (s2,val2)
#             return (s2, val2)

# Bottom up approach
# dp = [['' for i in range(m+1)] for j in range(n+1)]
# for i in range(1,n+1):
#     for j in range(1,m+1):
#         if len(dp[i][j]) < len(dp[i-1][j]):
#             dp[i][j] = dp[i-1][j]
#         if len(dp[i][j]) < len(dp[i][j-1]):
#             dp[i][j] = dp[i][j-1]
#         if s[i-1] == t[j-1]:
#             if len(dp[i][j]) < len(dp[i-1][j-1]) + 1:
#                 dp[i][j] = dp[i-1][j-1] + s[i-1]
# print (dp[-1][-1])