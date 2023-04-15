import sys
sys.setrecursionlimit(10**6)

n = int(input())
arr = list(map(float, input().split()))

dp = [[-1 for i in range(n+1)] for j in range(n+1)]

# Aim: Multiply all probabilities having no_heads > no_tails
# Top down approach
def ans(i, no_heads):
    global n, arr
    # Base case: Total heads used > total tails used, multiply all probabilites or probability = 0
    if i == n:
        if no_heads > n - no_heads: 
            return 1
        else:
            return 0
            
    # If subproblem already solved, use it
    if dp[i][no_heads] != -1:
        return dp[i][no_heads]
    else:
        if dp[i+1][no_heads+1] != -1:
            val1 = dp[i+1][no_heads+1]
        else:
            val1 = ans(i+1, no_heads+1)
        if dp[i+1][no_heads] != -1:
            val2 = dp[i+1][no_heads]
        else:
            val2 = ans(i+1, no_heads)
        
        # Two cases possible at ith coin
        # Case 1: Take heads, add no_heads + 1, multiply with heads probability
        # Case 2: Take tails, multiply with tails probability

        dp[i][no_heads] = arr[i]*val1 + (1-arr[i])*val2
        return dp[i][no_heads]

print (ans(0, 0))