# ������ ���� ������ �����մϴ�.

### ����Լ� + for�ȿ��� basecase���� reture�� if+return�� ����

```cpp
bool dfs(int x,int c){
	check[x] = c;
	for(int i = 0 ; i < graph[x].size() ; i++){
		int node = graph[x][i];
		if(check[node] == 0){
			//FB1.��� for���� �ߴܽ�Ű��, dfs�� �۵���Ű�ݾ�
			//return dfs(node,3-c);.0
			//�̳༮�� �ش� ���ǿ� ������ �Լ� �ߴ� false��ȯ / �ƴϸ� keep
			if(dfs(node,3-c) == false){return false;}
		}
		else if(check[node] == c){
			return false;
		}
	}
	return true;
}
```

### ���� ����Ʈ���� ����� �ֺ� ���� graph[x][j] �̴�.

```cpp
		bool isBi = true;
		for(int i = 1; i <= n; i++){
			for(int j = 0;  j < graph[i].size(); j++){
				int nnode = graph[i][j];
				//FB.
				//if(check[i] == check[nnode]){
				//	isBi = false;
				//}
				if(check[i] == check[nnode]){
					isBi = false;
				}
			}
		}
```

### for + return�� ��

```cpp
int length(int a, int p, int checknum)
{
    check[a] = checknum;
    int b = next(a, p);
    if (check[b] != 0)
    {
        return check[b] - 1;
    }
    else
    { //FB.return�� ��������, �Լ��� ����ǰ� ����� ������ �ȵ���..
        return length(b, p, checknum + 1);
    }
}
```

### 2���� �迭 �ʱ�ȭ by fill

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int check[2][2];
    check[0][0] = 1;
    check[0][1] = 2;
    check[1][0] = 3;
    check[1][1] = 4;
    fill(&check[0][0], &check[1][1] + 1, 0);
}
```

### bfs - �湮�� - ������ check�� 0 ���� ��

```cpp
    queue<int> q;
    q.push(x);
    //FB. �湮 ������ 0 �� ������ �ȵ���.......n =5 k = 5 �� �ٷ� ã�� 0�� ����ε�, 2�� ���͹���.
	//check[x] = 0;
    check[x] = 1;
    while (!q.empty())
```

### database �ʵ� ���鶧 ��Ģ �����ϱ�.

- ��Ʈ�ι̳� �� ����

```
 a[��Ʈ�ι̳��� 19���� ����� ���?][ 3���� ���� �����?][ x,y ��ǥ �ϳ� ���]
```

```cpp
int a[19][3][2] = {
    {{0, 1}, {0, 2}, {0, 3}},
    {{1, 0}, {2, 0}, {3, 0}},
    {{1, 0}, {1, 1}, {1, 2}},
    {{0, 1}, {1, 0}, {2, 0}},
    {{0, 1}, {0, 2}, {1, 2}},
    {{1, 0}, {2, 0}, {2, -1}},
    {{0, 1}, {0, 2}, {-1, 2}},
    {{1, 0}, {2, 0}, {2, 1}},
    {{0, 1}, {0, 2}, {1, 0}},
    {{0, 1}, {1, 1}, {2, 1}},
    {{0, 1}, {1, 0}, {1, 1}},
    {{0, 1}, {-1, 1}, {-1, 2}},
    {{1, 0}, {1, 1}, {2, 1}},
    {{0, 1}, {1, 1}, {1, 2}},
    {{1, 0}, {1, -1}, {2, -1}},
    {{0, 1}, {0, 2}, {-1, 1}},
    {{0, 1}, {0, 2}, {1, 1}},
    {{1, 0}, {2, 0}, {1, 1}},
    {{1, 0}, {2, 0}, {1, -1}},

};
```

- �÷��� �� dx,dy ���� �ΰ��� ���

- ������ ���

```cpp
dx = { 0,0,-1,1};
dy = { 1,-1, 0,0};
```

```
d[��� ������� ����?][x,y��ǥ �����?]
```

```cpp
d = { {0,1}, {0,-1},{1,0},{-1,0}};
```

### ���ĸ� �ϰ� ����������������, ��� ������ ���� �ʴ°�!! | sort + next_permutation �� ���� �� ��Ʈ

### ����Լ� �����Ҷ�, baseCase�ɷ����°ſ���, ������ �ƴѰ�찡 ���� �����ϱ� Ʋ���� �Ǵ� case�� �־���.

```cpp
    //FB, �� �����츦 ���� �������Ѵ�.
    //�� ������, ������� ���� ����� 6�̾�, && next�ѹ��� ���������� ���� �ɼ��ִ�.
    if (current.size() == 6)
    {
        printNumber(current);
        return;
    }
    //�� ��������, ���̻� nextNumber�� ����.
    if (number.size() == nextNumber)
    {
        return;
    }
```

### DFS check�� ���� �� = ���� ���� ��尡 check�� �ȵ�������, check�ϰ� .. �� ���� =>ó�� �����ϴ� ��尡 üũ�� �ȵ�

```cpp
void dfs(int x)
{
    //���
    cout << x << " ";

    //�ֺ� ������ ���鼭, �湮���ߴٸ� �湮���ֱ�.
    for (int i = 0; i < graph[x].size(); i++)
    {
        int next = graph[x][i];
        cout << "DEBUG" << x << " => " << next << "\n";
        if (check[next] == 0)
        {
            //fb) �� �ڵ忡���� ó�� 1�� ���ö�, check�� ���ϱ⶧���� �ٽ� 1�� �湮�ϰ� �ɲ���.
            //check[x] = 1;
            dfs(next);
        }
    }
}
```

### �����ϰ� ������, ������ ���ϴ� �Լ�, �Ű����� �ִ°� �״�� �����~

```
//fb,�� �Ű����� xȰ�� ���ϴ°ž�? - x�� ���ڸ������� p�� ���� ��� ����ϱ�.
// int nextNode(int x)
// {
//     int sum = 0;
//     do
//     {
//         int a = x / 10;
//         int b = x % 10;
//         sum += pow(b, p);
//     } while (a != 0);
//     return sum;
// }
int nextNode(int x)
{
    int sum = 0;
    while (x != 0)
    {
        sum += pow(x % 10, p);
        x = x / 10;
    }
    return sum;
}
```
