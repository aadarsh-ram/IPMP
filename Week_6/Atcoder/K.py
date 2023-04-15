import sys
sys.setrecursionlimit(10**9)

# Use C++ solution for AC

n, k = list(map(int, input().split()))
arr = list(map(int, input().split()))

def opp(x):
    if x == 1: return 2
    if x == 2: return 1

dp = {}
def ans(rem, move):
    global arr, dp
    # print (rem, move)
    who_win = opp(move)
    if dp.get((rem, move-1), -1) != -1:
        return dp.get((rem, move-1))
    for i in arr:
        if rem-i >= 0:
            if dp.get((rem-i, opp(move)-1), -1) != -1:
                if dp.get((rem-i, opp(move)-1), -1) == move:
                    who_win = move
                    break
            if ans(rem-i, opp(move)) == move:
                who_win = move
                break
    dp[(rem,move-1)] = who_win
    return who_win

if (ans(k, 1)) == 1:
    print ("First")
else:
    print ("Second")