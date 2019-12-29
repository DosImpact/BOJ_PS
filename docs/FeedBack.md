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
