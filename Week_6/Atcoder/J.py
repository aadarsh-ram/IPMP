'''
# Defining terms:

Let c0, c1, c2, c3 be the no. of plates with sushis 0, 1, 2, 3 respectively.
Let events A, B, C, D correspond to eating 1 sushi from plates containing 0, 1, 2, 3 sushis.
E(A), E(B), E(C), E(D) be the expected no. of operations of events A, B, C, D.

# Aim: To get from state (c0, c1, c2, c3) to (n, 0, 0, 0) and find the expected no of operations.

# Calculation of expected value:

E(A) = (c0/n)*(1+E(A)) + (c1/n)*(1+E(B)) + (c2/n)*(1+E(C)) + (c3/n)*(1+E(D))

In the term (c1/n)*(1+E(B)) -
"c1/n" refers to the probability of eating from plates having 1 sushi.
"1" refers to the operation of eating from a plate having 1 sushi.
If not eaten, we add the expected no. of turns "E(B)" taken to get from current state to (n, 0, 0, 0).

Similarly, we can extrapolate for the other terms.

Reducing the above formula,

E(A) = (c0+c1+c2+c3)/n + (c0/n)*E(A) + (c1/n)*E(B) + (c2/n)*E(C) + (c3/n)*E(D)
(1- (c0/n)) * E(A) =  1 + (c1/n)*E(B) + (c2/n)*E(C) + (c3/n)*E(D)
E(A) = (1 + (c1/n)*E(B) + (c2/n)*E(C) + (c3/n)*E(D)) / (1-(c0/n))

c0 = n - (c1+c2+c3)
So, E(A) = (1 + (c1/n)*E(B) + (c2/n)*E(C) + (c3/n)*E(D)) / ((c1+c2+c3)/n)

# Reference: https://www.youtube.com/watch?v=apeONhTuYUU
'''
import sys
sys.setrecursionlimit(10**6)

n = int(input())
arr = list(map(int, input().split()))

c1,c2,c3 = 0,0,0
# Calulating no. of plates with sushi 1, 2, 3
for i in arr:
    if i == 1: c1 += 1
    if i == 2: c2 += 1
    if i == 3: c3 += 1

dp = [[[-1 for i in range(n+1)] for j in range(n+1)] for k in range(n+1)]

def ans(i,j,k):
    global n
    # Base state
    if (i+j+k) == 0:
        return 0
    if dp[i][j][k] != - 1:
        return dp[i][j][k]
    
    val1,val2,val3 = 0,0,0
    # If the number of plates becomes < 0, then the expected value = 0 from that state
    # If state already visited, use that expected value
    if (i > 0):
        if dp[i-1][j][k] != -1:
            val1 = (i/n)*dp[i-1][j][k]
        else:    
            val1 = (i/n)*ans(i-1, j, k)
    if (j > 0):
        if dp[i+1][j-1][k] != -1:
            val2 = (j/n)*dp[i+1][j-1][k]
        else:
            val2 = (j/n)*ans(i+1,j-1,k)
    if (k > 0):
        if dp[i][j+1][k-1] != -1:
            val3 = (k/n)*dp[i][j+1][k-1]
        else:
            val3 = (k/n)*ans(i,j+1,k-1)
    
    dp[i][j][k] = (1+val1+val2+val3)/((i+j+k)/n)
    return dp[i][j][k]

print (ans(c1,c2,c3))