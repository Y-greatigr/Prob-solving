def d(k):
    a=list()
    for i in range(k):
        d=int(input())
        if d!=0:
            a.append(d)
        else:
            a.pop()
    print(sum(a))


if __name__ == '__main__':
    ka = int(input())
    d(ka)