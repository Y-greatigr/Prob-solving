import sys
n = int(sys.stdin.readline())
d=list()
index=0
for i in range(n):
    a = sys.stdin.readline().split()
    if a[0]=='push':
        d.append(a[1])
    elif a[0]=='front':
        if(len(d)-index==0):
            print('-1')
        else:
            print(d[index])
    elif a[0]=='back':
        if (len(d)-index == 0):
            print('-1')
        else:
            print(d[len(d)-1])
    elif a[0]=='pop':
        if (len(d)-index == 0):
            print('-1')
        else:
            print(d[index])
            index+=1
    elif a[0]=='size':
        print(len(d)-index)
    elif a[0]=='empty':
        if len(d)-index==0:
            print('1')
        else:
            print('0')