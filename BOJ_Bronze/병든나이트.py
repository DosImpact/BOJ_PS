

import sys


def input(): return sys.stdin.readline().rstrip()


N, M = map(int, input().split())

if N == 1:
    print(1)
elif N == 2:
    print(min(4, (M+1)//2))
    # if ((M+1) // 2) >= 3:
    #     print(4)
    # else:
    #     print(((M+1)//2)+1)
else:

    # if M <= 6:
    #     print(min(4, M))
    # else:
    #     print(M-2)
    ans = [-1, 1, 2, 3, 4, 4, 4, 5, 6]
    if M <= 8:
        print(ans[M])
    else:
        print(M-2)

    # if M <= 4:
    #     print(M)
    # elif M <= 8:
    #     print(4 + (M-4)//2)
    # else:
    #     print(6 + (M - 8))

"""

병든 나이트는 여행을 시작하려고 하고, 여행을 하면서 방문한 칸의 수를 최대로 하려고 한다. 병든 나이트의 이동 횟수가 4번보다 적지 않다면, 이동 방법을 모두 한 번씩 사용해야 한다. 이동 횟수가 4번보다 적은 경우(방문한 칸이 5개 미만)에는 이동 방법에 대한 제약이 없다.



﻿﻿1. 병든 나이트의 이동 횟수가 4번보다 적지 않다면, 이동 방법을 모두 한 번씩 사용해야 한다.

﻿=> 이동횟수 5번이상 = 방문 칸 6 이상  => 이동방법제약 있음

﻿2.﻿이동 횟수가 4번보다 적은 경우(방문한 칸이 5개 미만)에는 이동 방법에 대한 제약이 없다.

﻿﻿﻿=> 이동횟수 3번이하 = 방문 칸 4 이하 => 이동방법제약 있음

﻿

﻿제가 문제가 된 케이스는 ﻿

﻿input : 3 6 인데

저는 5라고 생각했는데 답은 4 더군요 .! ﻿



문제 해석을 제가 틀리게 한듯한데.
다음 1번 2번 조건의 없는부분이 다음처럼 있게되더라고요.

﻿﻿﻿﻿﻿﻿﻿﻿=> 이동횟수 4번 = 방문 칸 5 => 이동방법제약 있음? 없음 ? 
﻿

 ﻿4번보다 적지 않다면 을 4이상으로 생각한다면
﻿
﻿﻿1. 병든 나이트의 이동 횟수가 4번보다 적지 않다면, 이동 방법을 모두 한 번씩 사용해야 한다.

﻿=> 이동횟수 4번이상 = 방문 칸 5 이상 => 이동방법제약 있음

﻿﻿4번보다 적다  = ( x < 4 )

﻿4번보다 적지 않다면 = ( x < 4 ) 의 반대 =  x>= 4 = ﻿ 4이상
﻿

﻿

"""
