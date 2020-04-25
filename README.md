# BOJ !

## 풀었던 로그

```python
memo
```

# 20-04-25

- 이분탐색
- 이분탐색 개념화
- 이분탐색 fb) 범위 설정의 오류

```python

import sys

def input(): return sys.stdin.readline().rstrip()


Debug = True

Budgets = None
AllMoney = None


def isOk(limit: int):
    res = 0
    for l in Budgets:
        if l >= limit:
            res += limit
        else:
            res += l
    if res <= AllMoney:
        return True
    else:
        return False


def search(head, tail):
    if Debug:
        print(f"search {head} ~{tail}")
    if head + 1 == tail:
        return head
    # 연산을 해, 예산 에 따라서, 두개로 search를 분기하자.
    mid = (head+tail)//2
    if isOk(mid):
        return search(mid, tail)
    else:
        return search(head, mid)


def solution(budgets, M):
    global Budgets, AllMoney
    AllMoney = M
    Budgets = budgets
    Budgets.sort()
    # return search(min(budgets), max(budgets))# fb 아니 예산을 다 못주는 경우와, 다 줄수있는 경우는?
    return search(0, max(Budgets)+1)


print(solution(	[12, 11, 14, 10], 3))

"""
fb)
이분 탐색의 범위를 설정할때,

search(head,tail) > 의미를 부여
tail부분의 값은 절때 이 값은 줄 수 없다.
head 부분의 값은 이 값으로줄수 있다.
[head,tail) 부분의 값은 줄수도, 혹은 안줄 수도.

fb) 이분탐색 개념화

when . 오름차순으로 정렬된 수열에서, 특정한 수를 찾고 싶어.
그럴때, 조건에 안맞는 범위는 아예 배제를 해버리고 특정 범위만을 지정해서 찾아보자.

[head,tail) 범위의 값중에 하나가 답이 되는데
범위가 좁혀져서 head+1 == tail 이 되면 탐색을 종료 한다.

"""

```
