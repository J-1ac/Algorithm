import sys

n=int(sys.stdin.readline())                                                              #error sys.stdin.readline 0 1 0
error_num=int(sys.stdin.readline())
if error_num!=0:
    error=list(map(int,sys.stdin.readline().split()))
count_forward,count_backward=len(str(n)),len(str(n))
if n>0:
    n_forward=n-1
else:
    n_forward=0
n_backward=n+1
ispossible=True
if error_num==0:
    print(len(str(n)))
elif error==[1,2,3,4,5,6,7,8,9]:
    print(n+1)
else:
    if n==100:
        print(0)
    else:
        for i in str(n):
            if int(i) in error:
                while True:
                    if n_forward==0:
                        count_forward=n
                        break
                    for i in str(n_forward):
                        if int(i) in error:
                            n_forward-=1
                            count_forward+=1
                            break
                    else:
                        break
                    
                while True:    
                    for i in str(n_backward):                                 
                        if int(i) in error:
                            n_backward+=1
                            count_backward+=1
                            break
                    else:
                        break

                if count_forward>=count_backward:
                    print(count_backward+1)
                else:
                    print(count_forward+1)
                break
        else:
            print(1)