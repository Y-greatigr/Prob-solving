N, M=map(int, input().split())
k=list(map(int, input().split()))
index, count = 0, 0
num=[i+1 for i in range(N)]

while True:
    if len(k) == 0:
        break
    way1 = abs(index - num.index(k[0]))
    way2 = len(num) - abs(index-num.index(k[0]))
    count += min(way1, way2)
    index = num.index(k[0])
    k.pop(0)
    num.pop(index)
print(count)