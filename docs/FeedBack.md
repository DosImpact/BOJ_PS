# ������ ���� ������ �����մϴ�.

### ����Լ� + for�ȿ��� basecase���� reture�� if+return�� ����

```
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

```
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
