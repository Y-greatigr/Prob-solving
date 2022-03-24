k = int(input())
ar=list()
command=list()
for i in range(k):
    a=input()
    a=a.split()
    if a[0]=='push':
        ar.append(a[1])
    elif a[0]=='pop':
        if(len(ar)!=0):
            command.append(ar.pop())
        else:
            command.append('-1')
    elif a[0]=='top':
        if (len(ar) != 0):
            command.append(ar[len(ar)-1])
        else:
            command.append('-1')
    elif a[0]=='size':
        command.append(len(ar))
    elif a[0]=='empty':
        if(len(ar)==0):
            command.append('1')
        else:
            command.append('0')


for i in range(len(command)):
    print(command[i])