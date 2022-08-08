T=int(input())
for i in range(T):
    n, m = map(int, input().split())
    k=list(map(int, input().split()))
    kli=[0 for i in range(n)]
    kli[m]=1
    count=1
    while True:
        if k[0]==max(k):
            if kli[0]==1:
                print(count)
                break
            else:
                k.pop(0)
                kli.pop(0)
                count+=1
        else:
            k.append(k.pop(0))
            kli.append(kli.pop(0))