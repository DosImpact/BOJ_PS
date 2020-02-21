
import sys


def input(): return sys.stdin.readline().rstrip()


def solution(n, words):
    memo = {}
    cnt = [0, 1]  # 사람(1,2), 차례
    isEnd = False
    for i in range(len(words)):
        # 단어들을 탐색 | 해당 차례를 만든다. | 해당 차례 단어가 올바른지 판단
        cnt = [cnt[0]+1, cnt[1]] if cnt[0]+1 <= n else [1, cnt[1]+1]
        if i == 0:
            # memo[str(words[i])] = 1 FB) 처음에 말한 경에도 , 체크를 해줘야지.
            memo[str(words[i])] = 1
        else:
            # 그전 단어와 끝말잇기가 되소 | 처음 말하는 단어라면
            if(words[i-1][-1] == words[i][0] and words[i] not in memo):
                memo[str(words[i])] = 1

            else:
                isEnd = True
                break
    if not isEnd:
        return [0, 0]
    return cnt


solution(3, ["tank", "kick", "know", "wheel",
             "land", "dream", "mother", "robot", "tank"])

"""
FB) 첫 단어를 말할때도 체크를 해 주어야 한다.

RF)  리팩토링 : 미쳤다....
def solution(n, words):
    for p in range(1, len(words)):
        if words[p][0] != words[p-1][-1] or words[p] in words[:p]: return [(p%n)+1, (p//n)+1]
    else:
        return [0,0]

"""
