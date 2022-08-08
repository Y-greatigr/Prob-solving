/*
문제
루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.

출력
첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다.

예제 입력 1
7
1 6
6 3
3 5
4 1
2 4
4 7
예제 출력 1
4
6
1
3
1
4
*/

#include <iostream>
#include <vector>

using namespace std;

vector <int> tree[100001];
bool v[100001];
int a[100001];

void dfs(int node) {
	v[node] = true;
	for (int j = 0; j < tree[node].size(); j++) {
		int i = tree[node][j];

		if (!v[i]) {
			a[i] = node;
			dfs(i);
		}
	}
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int count, from, to;
	cin >> count;

	for (int i = 1; i < count; i++) {
		cin >> from >> to;
		tree[from].push_back(to);
		tree[to].push_back(from);
	}
	
	dfs(1);

	for (int i = 2; i <= count; i++)
		cout << a[i] << "\n";

	return 0;
}