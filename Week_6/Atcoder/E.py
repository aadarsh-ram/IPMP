import sys
import io,os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
print = sys.stdout.write
sys.setrecursionlimit(1000000)

from math import inf

n, wt = list(map(int, input().split()))
all_inp = []
for i in range(n):
    x,y = list(map(int, input().split()))   
    all_inp.append([x,y])
all_inp.sort()

dp = [[-1 for i in range(10**5+1)] for j in range(n+1)]

# Aim: Minimizing weight to get to a given value 
def ans(curr_ind, val):
    global all_inp
    # Base Cases
    if curr_ind < 0 and val == 0:
        return 0
    if (curr_ind < 0 and val != 0) or (val < 0):
        return inf
    if dp[curr_ind][val] != -1:
        return dp[curr_ind][val]

    # Taking current value into account
    if dp[curr_ind-1][val-all_inp[curr_ind][1]] != -1:
        wt1 = all_inp[curr_ind][0] + dp[curr_ind-1][val-all_inp[curr_ind][1]]
    else:
        wt1 = all_inp[curr_ind][0] + ans(curr_ind-1, val-all_inp[curr_ind][1])
    # Not taking current value into account
    if dp[curr_ind-1][val] != -1:
        wt2 = dp[curr_ind-1][val]
    else:
        wt2 = ans(curr_ind-1, val)

    # Minimizing curr_ind_wt
    dp[curr_ind][val] = min(wt1, wt2)
    return dp[curr_ind][val]

# Since max_value attainable is 100*1000 = 10^5;
# We can iterate through all values and find maximum value which satisfies weight limit
max_ans = 0
for i in range(10**5+1):
    if ans(n-1, i) <= wt:
        max_ans = max(max_ans, i)
print (str(max_ans))
