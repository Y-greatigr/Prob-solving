import sys
n = int(sys.stdin.readline())
d=list()
for i in range(n):
    d.append(i+1)
i=0
while n>1:
    i+=1
    d.append(d[i])
    i+=1
    n-=1
print(d[i])