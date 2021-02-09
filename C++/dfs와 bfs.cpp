/*
<알고리즘 분류>
그래프 이론
그래프 탐색
너비 우선 탐색
깊이 우선 탐색

문제
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 
단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 
더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

입력
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 
탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 
두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 
입력으로 주어지는 간선은 양방향이다.

출력
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다.
V부터 방문된 점을 순서대로 출력하면 된다.

예제 입력 1 
4 5 1
1 2
1 3
1 4
2 4
3 4
예제 출력 1 
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