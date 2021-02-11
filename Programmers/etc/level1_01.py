from collections import deque
import sys

SIZE = 101


def input(): return sys.stdin.readline().rstrip()


def solution(s):
    answer = []
    # ���ڿ� ���̸�ŭ 1~len(s) for�� - i���� �ɰ��� �迭�� ���� -> �����Ÿ� ���ϴ� �Լ� -> ���� ����
    for i in range(1, len(s)+1):
        var = []
        for j in range(0, len(s), i):  # j
            var.append(s[j: j+i])
        res = ""
        count = 1
        for i in range(len(var)-1):
            if(var[i] == var[i+1]):  # ���������  count����
                count += 1
            else:  # �ٸ������ ���ڿ� ����� �ֱ� -> count �� 2�̻���� �����ؼ� �ٿ��ֱ�
                if count == 1:
                    res += var[i]
                else:
                    res += (str(count) + var[i])
                count = 1
        if count == 1:
            res += var[-1]
        else:
            res += (str(count) + var[-1])
        answer.append(len(res))
    return min(answer)


s = "xababcdcdababcdcd"
solution(s)
