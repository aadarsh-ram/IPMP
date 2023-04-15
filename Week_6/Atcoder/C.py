import atexit
import io
import sys
_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())

sys.setrecursionlimit(10**6)

all_act = []
n = int(input())
for test in range(n):
    arr = list(map(int, input().split()))
    all_act.append(arr)

dp = []
for i in range(n):
    dp.append([-1,-1,-1])

# Optimizing happiness by choosing highest value
# Needs to satisfy "cannot do the same activities for two or more consecutive days".
def ans(act_ind, ind):
    global all_act, dp
    if ind == n-1:
        return all_act[ind][act_ind]
    val1, val2 = -1, -1
    # If act_ind == 0; then next index can't be 0.
    if act_ind == 0:
        if dp[ind+1][1] != -1:
            val1 = dp[ind+1][1]
        if dp[ind+1][2] != -1:
            val2 = dp[ind+1][2]
        if val1 == -1:
            val1 = ans(1, ind+1)
        if val2 == -1:
            val2 = ans(2, ind+1)
    # If act_ind == 1; then next index can't be 1.
    if act_ind == 1:
        if dp[ind+1][0] != -1: 
            val1 = dp[ind+1][0]
        if dp[ind+1][2] != -1:
            val2 = dp[ind+1][2]
        if val1 == -1:
            val1 = ans(0, ind+1)
        if val2 == -1:
            val2 = ans(2, ind+1)
    # If act_ind == 2; then next index can't be 2.
    if act_ind == 2:
        if dp[ind+1][0] != -1: 
            val1 = dp[ind+1][0]
        if dp[ind+1][1] != -1:
            val2 = dp[ind+1][1]
        if val1 == -1:
            val1 = ans(0, ind+1)
        if val2 == -1:
            val2 = ans(1, ind+1)
    
    # Maximizing happiness
    dp[ind][act_ind] = all_act[ind][act_ind] + max(val1, val2)
    return dp[ind][act_ind]

# Find max happiness by starting from first, second or third activity
print (max(ans(0,0), ans(1,0), ans(2,0)))