import sys


def input(): return sys.stdin.readline().rstrip()


t = int(input())

for _ in range(t):
    x, y = map(int, input().split())
    dis = abs(x-y)

    ans = 0
    cnt = 1
    while dis >= cnt:
        if dis >= cnt*2:
            dis -= cnt*2
            ans += 2
        else:
            dis -= cnt
            ans += 1
        cnt += 1
    if dis > 0:
        ans += 1
    print(ans)

"""
fb)
알고리즘

두 좌표의 거리를 구한다.
생각은 처음 속도 1  마지막 속도 1 로 구성 ( 그리디 하게 )
남은 거리에 대해 또
생각은 처음 속도 2  마지막 속도 2 로 구성 ( 그리디 하게 )

이렇게, 처음과 시작을 동시에 채워나간다.

예를들어)

거리가 16이면

1,1 로 채워 > 14 거리 남음 ( cnt = 1)
1,2,2,1 채워 > 10 거리 남음 ( cnt = 2 )
1,2,3,3,2,1 채워 > 4 거리 남음 ( cnt = 3)
1,2,3,4,3,2,1 채워 > 완성 ( cnt = 4 ) 여기서는 4가 1번 채워졌다.
문제에 따라서, 4가 두번, 혹은 한번, 혹은 못채우는 경우가 생긴다.

거리가 15이면

1,1 로 채워 > 13 거리 남음 ( cnt = 1)
1,2,2,1 채워 > 9 거리 남음 ( cnt = 2 )
1,2,3,3,2,1 채워 > 3 거리 남음 ( cnt = 3)
1,2,3,3,2,1 채워 > 3 거리 남음 완성 ( cnt = 4 ) 여기서는 4가 못 채워졌다.
> 하지만 남은 거리 3은, 지금까지 행적을 보면 3,3 이 반드시 있고, 이 사이 어디를 들어가도 된다.
문제에 따라서, 4가 두번, 혹은 한번, 혹은 못채우는 경우가 생긴다.

거리가 14이면

1,1 로 채워 > 12 거리 남음 ( cnt = 1)
1,2,2,1 채워 > 8 거리 남음 ( cnt = 2 )
1,2,3,3,2,1 채워 > 2 거리 남음 ( cnt = 3)
1,2,3,3,2,1 채워 > 2 거리 남음 완성 ( cnt = 4 ) 여기서는 4가 못 채워졌다.
> 하지만 남은 거리 2은, 지금까지 행적을 보면 2,2 이 반드시 있고, 이 사이 어디를 들어가도 된다.

알맞게 count를 해주면 답!

(signed) int	-2,147,483,648 ~ 2,147,483,647
2^31 =  2,147,483,648

"""
