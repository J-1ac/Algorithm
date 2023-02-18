day=int(input())
cnt=0
cars=list(map(int,input().split()))
for i in range(5):
    if cars[i]%10 == day:
        cnt+=1
print(cnt)