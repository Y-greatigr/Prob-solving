import sys
sys.setrecursionlimit(10**9)

def f(st, en):
    if st>en:
        return

    root=a[st]
    ri=en
    while a[ri]>root:
        ri-=1
    f(st+1, ri)
    f(ri+1, en)
    print(root)


a=list()
n=0
while True:
    try:
       a.append(int(sys.stdin.readline()))
       n+=1
    except:
        break
f(0, n-1)