import sys
from collections import Counter

temp,lands=[],[]
n,m,b=map(int,sys.stdin.readline().split())
count,ispossible=1,True
for _ in range(n):
    temp.append(list(map(int,sys.stdin.readline().split())))
for i in range(n):
    for j in range(m):
        lands.append(temp[i][j])
lands.sort(reverse=True)
cnt=Counter(lands)
print(lands)
while True:
    target,time=cnt.most_common()[1][count],0
    for land in lands:
        if land>target:
            b+=land-target
            time+=1
        elif land<target:
            if b>0:
                b-=target-land
                time+=2
            else:
                ispossible=False
                break
    if ispossible:
        break
    count+=1

print(time)
#cnt부분 다시