# TLE
from collections import defaultdict
MOD = 10**9 + 7
mat = []
n = int(input())
for _ in range(n):
    lst = list(map(int, input().split()))
    mat.append(lst)

ind_one = [[] for i in range(n)]
for i in range(n):
    for j in range(n):
        if mat[i][j] == 1:
            ind_one[i].append(j)
# print (ind_one)

def ans(i,visited):
    if i == n:
        return 1
    way = 0
    for j in ind_one[i]:
        visited[j] += 1
        # print (j, visited[j])
        if (visited[j] == 1):
            way += ans(i+1, visited)%MOD
            del visited[j]
        elif (visited[j] > 1):
            visited[j] -=  1
    return way

print (ans(0,defaultdict(int))%MOD)