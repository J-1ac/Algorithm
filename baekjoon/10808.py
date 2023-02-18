mystr=input()
for i in range(97,123,1):
    cnt=0
    for mychr in mystr:
        if ord(mychr)==i:
            cnt+=1
    print(cnt,end=" ")