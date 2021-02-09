n=int(input())
c=list()
d=list()
x=1
flag=1
for i in range(1,n+1):
    a=int(input())
    while x<=a:
        c.append(x)
        d.append('+')
        x+=1

    e=c[len(c)-1]
    if e == a:
        d.append('-')
        c.pop()
    else:
        flag=0
        break
if(flag):
    for i in d:
        print(i)
else:
    print('NO')
