n,m=map(int,input().split())
a,b=[],[]
for i in range(n):
    a.append(list(map(int,input().split())))
for i in range(n):
    b.append(list(map(int,input().split())))
arr=[[None for j in range(m)] for i in range(n)]            #얕은 복사 방지
for i in range(n):
    for j in range(m):
        arr[i][j]=a[i][j]+b[i][j]
for i in range(n):
    print(*arr[i])