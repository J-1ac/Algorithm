n=int(input())
numl=list(map(int,input().split()))
findn=int(input())
count=0
for i in range(n):
    if numl[i]==findn:
        count+=1
print(count)