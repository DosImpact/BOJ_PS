
from itertools import combinations

# �� ������ ������ �������� ���ϱ�
def team(member):
    global allMember
    team1=list()
    team2=list()
    
    ## ��� �����ϱ�
    for i in allMember:
        if i in member:
            team1.append(i)
        else:
            team2.append(i) 
    ## ���� �Ŀ� ����ϱ�
    team1_points=0
    for i in team1:
        for j in team1:
            team1_points+=points[i][j]
            
    team2_points=0
    for i in team2:
        for j in team2:
            team2_points+=points[i][j]
    diff=abs(team1_points-team2_points)
#     print ("��1�� ����: ", team1_points)
#     print ("��2�� ����: ", team2_points)
#     print ("�Ŀ�����: ", diff)
#     print ("============")
    return diff


def solve(members):
    global combinations, min
    combinations=list(combinations(members, int(N/2)))
    case=int(len(combinations)/2)
    
    for i in range(case):
        num=combinations[i]
        value=team(num)
        if (value<min):
            min=value
    print ("���� ���: ", min)
    return (min)

N=8  #���� 1
points=[[0, 5, 4, 5, 4, 5, 4, 5],
        [4, 0, 5, 1, 2, 3, 4, 5],
        [9, 8, 0, 1, 2, 3, 1, 2],
        [9, 9, 9, 0, 9, 9, 9, 9],
        [1, 1, 1, 1, 0, 1, 1, 1],
        [8, 7, 6, 5, 4, 0, 3, 2],
        [9, 1, 9, 1, 9, 1, 0, 9],
        [6, 5, 4, 3, 2, 1, 9, 0]]
min=999999
allMember=[i for i in range(N)]
members=[i for i in range(N)]
solve(members)
