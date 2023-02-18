T=int(input())
for _ in range(T):
    mystr=list(input())
    if len(mystr)==1:
        print(mystr[0]+mystr[0])
    else:
        print(mystr[0]+(mystr[len(mystr)-1]))