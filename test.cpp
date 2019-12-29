#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define SIZE 51
using namespace std;

int graph[SIZE][SIZE];
int check[SIZE][SIZE];
int dx[8] = {0, 0, 1, -1, -1, 1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int w, h;

void dfs(int x, int y, int num)
{
    check[x][y] = num;
    for (int k = 0; k < 8; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        //FB1. �����˻�
        if (nx < 0 || ny < 0 || nx >= w || ny >= h)
        {
            continue;
        }
        if (graph[nx][ny] == 1 && check[nx][ny] == 0)
        {
            dfs(nx, ny, num);
        }
    }
}

int main()
{

    while (scanf("%d %d", &h, &w))
    {
        if (w == 0 && h == 0)
            break;
        //üũ�� �׷����� �ʱ�ȭ �ؾ���
        memset(check, 0, sizeof(check));
        memset(graph, 0, sizeof(graph));
        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; j++)
            {
                int tmp;
                scanf("%d", &tmp);
                graph[i][j] = tmp;
            }
        }
        int num = 0;
        for (int i = 0; i < w; i++)
        {
            for (int j = 0; j < h; j++)
            {
                // �׷����� 1�̿��� ���� �ϰ� �� üũ�� 0�̿��ߵ�.
                if (graph[i][j] == 1 && check[i][j] == 0)
                {
                    dfs(i, j, ++num);
                }
            }
        }

        printf("%d\n", num);

        // for(int i = 0; i < w; i++){
        // 	for(int j = 0 ; j < h ; j++){
        // 		printf("%d ",check[i][j]);
        // 		//printf("%d ",graph[i][j]);
        // 	}
        // 	printf("\n");
        // }
        // 		printf("\n");		printf("\n");
        // for(int i = 0; i < w; i++){
        // 	for(int j = 0 ; j < h ; j++){
        // 	//	printf("%d ",check[i][j]);
        // 		printf("%d ",graph[i][j]);
        // 	}
        // 	printf("\n");
        // }
    }
    return 0;
}