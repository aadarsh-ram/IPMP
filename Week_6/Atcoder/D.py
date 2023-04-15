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

sys.setrecursionlimit(1000000)
n, wt = list(map(int, input().split()))
all_inp = []
for i in range(n):
    x,y = list(map(int, input().split()))   
    all_inp.append([x,y])

dp = [[-1 for i in range(wt+1)] for j in range(n+1)]

# Aim: Maximizing value within weight limit
# Here, value <= 10^9; So, we are recursively going through weight, in order to maximize value
def ans(curr_wt, ind):
    global dp, all_inp, n
    # Base case
    if ind >= n or curr_wt == 0:
        return 0
    if dp[ind][curr_wt] != -1:
        return dp[ind][curr_wt]

    # If curr_ind_wt > curr_wt; Need to check next index, without taking value of curr_ind_wt
    if all_inp[ind][0] > curr_wt:
        if dp[ind+1][curr_wt] != -1:
            val = dp[ind+1][curr_wt]
        else:
            val = ans(curr_wt, ind+1)
        dp[ind+1][curr_wt] = val    
        return val
    else:
        # Taking curr_ind_wt into account
        if dp[ind+1][curr_wt-all_inp[ind][0]] != -1:
            val1 = all_inp[ind][1]+dp[ind+1][curr_wt-all_inp[ind][0]]
        else:
            val1 = all_inp[ind][1]+ans(curr_wt-all_inp[ind][0], ind+1)

        # Not taking curr_ind_wt into account
        if dp[ind+1][curr_wt] != -1:
            val2 = dp[ind+1][curr_wt]
        else:
            val2 = ans(curr_wt, ind+1)
        
        # Maximizing value
        dp[ind][curr_wt] = max(val1,val2)
        return dp[ind][curr_wt]

print (ans(wt, 0))