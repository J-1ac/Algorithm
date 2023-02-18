mystr=list(input())
for i in range(len(mystr)):
    if ord(mystr[i])<97:
        mystr[i]=chr(ord(mystr[i])+32)
    else:
        mystr[i]=chr(ord(mystr[i])-32)
for i in range(len(mystr)):
    print(mystr[i],end="")