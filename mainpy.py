
def minDist(arr, here, there):
    return min([abs((0+here) - there), abs((len(arr) + here) - there)])


def minDist_dir(arr, here, there1, there2):
    return -1 if (minDist(arr, here, there1) - minDist(arr, here, there2)) > 0 else 1


def solution(name):
    check = [0 for _ in range(len(name))]
    Ans = 0

    for i, n in enumerate(name):
        if n != 'A':
            check[i] = 1
    now = 0
    if check[now] == 1:
        check[now] = 0
        Ans += min([abs(ord(name[now]) - ord('A')),
                    abs(ord(name[now]) - (ord('Z')+1))])

    if check.count(1) <= 0:
        return Ans

    while(True):
        pos1 = check.index(1)
        pos2 = (len(check) - 1) - (check[::-1].index(1))
        nextpos = pos2 if (minDist(check, now, pos1) -
                           minDist(check, now, pos2)) > 0 else pos1
        Ans += minDist(check, now, nextpos)
        now = nextpos
        Ans += min([abs(ord(name[now]) - ord('A')),
                    abs(ord(name[now]) - (ord('Z')+1))])
        check[now] = 0
        # 바꿔
        if check.count(1) <= 0:
            break
    return (Ans)


print(solution("JAN"))
# print(solution("ABAAAAAAABA"))


"""
무조건 한 방향으로만 가야한다는 말은 틀렸네....!!!!!!!

"""
