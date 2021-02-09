b = list()

while True:
    a = input()
    if a == '.':
        break
    b.append(a)

for i in range(len(b)):
    c=list()
    flag=1
    for j in range(len(b[i])):
        d=b[i][j]
        if d=='(' or d=='[':
            c.append(d)
        elif d==')':
            if len(c)!=0 and c[len(c)-1]=='(':
                c.pop()
            else:
                flag=0
                break
        elif d==']':
            if len(c)!=0 and c[len(c)-1]=='[':
                c.pop()
            else:
                flag=0
                break
    if(flag==0 or len(c)!=0):
        print('no')
    else:
        print('yes')
