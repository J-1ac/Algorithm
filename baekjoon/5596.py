mk=list(map(int,input().split()))
ms=list(map(int,input().split()))
tmk,tms=0,0

for scroe in mk:
    tmk+=scroe
for scroe in ms:
    tms+=scroe

print(max(tmk,tms))