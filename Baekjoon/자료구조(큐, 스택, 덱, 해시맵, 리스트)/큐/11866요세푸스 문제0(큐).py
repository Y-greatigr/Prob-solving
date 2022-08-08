n, k = map(int, input().split())
d=list()
for i in range(1, n+1):
    d.append(i)
index=k-1
print('<', end='')
while len(d)>0:
    if len(d)==1:
        print(d.pop(index), end='>')
        break
    print(d.pop(index), end=', ')
    if index+k-1<len(d):
        index+=k-1
    else:
        index = (index+k-1)%len(d)