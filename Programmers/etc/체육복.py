def solution(n, lost, reserve):
    answer = 0
    datalist = [1]*n  # 0,1,2,3,4 �� �����
    for i in lost:
        datalist[i-1] -= 1
    for i in reserve:
        datalist[i-1] += 1
    for i, val in enumerate(datalist):
        if val == 0:  # ���� �޻������ ���� | �ε��� üũ | 2���� üũ | 2->1 , 0 -> 1
            if(i-1 >= 0 and datalist[i-1] == 2):
                datalist[i-1] -= 1
                datalist[i] += 1
            elif(i+1 <= len(datalist)-1 and datalist[i+1] == 2):
                datalist[i+1] -= 1
                datalist[i] += 1
    answer = len(list(filter(lambda x: x == 1 or x == 2, datalist)))
    print(answer)
    return answer
