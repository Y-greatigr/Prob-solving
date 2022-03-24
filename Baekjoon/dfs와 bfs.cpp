/*
<�˰��� �з�>
�׷��� �̷�
�׷��� Ž��
�ʺ� �켱 Ž��
���� �켱 Ž��

����
�׷����� DFS�� Ž���� ����� BFS�� Ž���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
��, �湮�� �� �ִ� ������ ���� ���� ��쿡�� ���� ��ȣ�� ���� ���� ���� �湮�ϰ�, 
�� �̻� �湮�� �� �ִ� ���� ���� ��� �����Ѵ�. ���� ��ȣ�� 1������ N�������̴�.

�Է�
ù° �ٿ� ������ ���� N(1 �� N �� 1,000), ������ ���� M(1 �� M �� 10,000), 
Ž���� ������ ������ ��ȣ V�� �־�����. ���� M���� �ٿ��� ������ �����ϴ� 
�� ������ ��ȣ�� �־�����. � �� ���� ���̿� ���� ���� ������ ���� �� �ִ�. 
�Է����� �־����� ������ ������̴�.

���
ù° �ٿ� DFS�� ������ �����, �� ���� �ٿ��� BFS�� ������ ����� ����Ѵ�.
V���� �湮�� ���� ������� ����ϸ� �ȴ�.

���� �Է� 1 
4 5 1
1 2
1 3
1 4
2 4
3 4
���� ��� 1 
1 2 4 3
1 2 3 4
*/
#include <iostream>
#include <queue>
using namespace std;

int** a;
int* b;
void makeArray(int N) {
	a = new int* [N];
	b = new int[N];

	for (int i = 0; i < N; i++) {
		a[i] = new int[N];
		b[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			a[i][j] = 0;
	}
}
void deleteArray(int N) {
	for (int i = 0; i < N; i++) {
		delete a[i];
	}
	delete a;
	delete b;
}
void dfs(int V, int N) {
	b[V] = 1;
	cout << V + 1 << " ";
	for (int i = 0; i < N; i++) {
		if (b[i] == 0 && a[V][i] == 1)
			dfs(i, N);
	}
}
void bfs(int V, int N) {
	queue<int> q;
	q.push(V);
	b[V] = 0;
	while (!q.empty()){
		V = q.front();
		q.pop();
		cout << V + 1 << " ";
		for (int i = 0; i < N; i++) {
			if (b[i] == 1 && a[V][i] == 1) {
				q.push(i);
				b[i] = 0;
			}
		}
	}
}
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M, V;

	cin >> N >> M >> V;

	makeArray(N);

	int c,d;
	for (int i = 0; i < M; i++) {
		cin >> c >> d;
		a[c-1][d-1] = 1;
		a[d-1][c-1] = 1;
	}

	dfs(V-1, N);
	cout << endl;
	bfs(V-1, N);

	deleteArray(N);
	return 0;
}