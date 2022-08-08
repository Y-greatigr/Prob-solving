import sys
s = int(sys.stdin.readline())
for j in range(s):
    command = sys.stdin.readline()
    n = int(sys.stdin.readline())
    test = sys.stdin.readline().rstrip()[1:-1].split(',')

    pendulum = 0
    index_front = 0
    index_back = len(test)-1
    len_command = len(command)-1
    i = 0
    flag = 0
    while i < len_command:
        if command[i] == 'R':
            pendulum += 1
        else:
            if index_front > index_back or test[0]=='':
                print('error')
                flag = 1
                break
            else:
                if pendulum % 2 == 0:
                    index_front += 1
                else:
                    index_back -= 1
        i += 1

    if flag == 1:
        continue
    else:
        print('[', end='')
        if index_front <= index_back:
            if pendulum % 2 == 0:
                for x in range(index_front, index_back):
                    print(test[x], end=',')
                print(test[index_back], end='')
            else:
                for x in range(index_back, index_front, -1):
                    print(test[x], end=',')
                print(test[index_front], end='')
        print(']')