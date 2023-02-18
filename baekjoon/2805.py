import sys
n,m=map(int,sys.stdin.readline().split())
trees=list(map(int,sys.stdin.readline().split()))
h_max,h_min,result=max(trees),0,0

while h_max>=h_min:
    middle,current_m=(h_max+h_min)//2,0
    for tree in trees:
        if tree>middle:
            current_m+=tree-middle
    if current_m>=m:
        result=middle
        h_min=middle+1
    else:
        h_max=middle-1
print(result)