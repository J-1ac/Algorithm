l,p=map(int,input().split())
mylist=list(map(int,input().split()))
diff=[]
for i in range(5):
    diff.append(mylist[i]-l*p)
print(*diff)