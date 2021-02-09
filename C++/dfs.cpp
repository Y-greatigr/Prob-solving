/*
����
��Ʈ ���� Ʈ���� �־�����. �̶�, Ʈ���� ��Ʈ�� 1�̶�� ������ ��, �� ����� �θ� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ����� ���� N (2 �� N �� 100,000)�� �־�����. ��° �ٺ��� N-1���� �ٿ� Ʈ�� �󿡼� ����� �� ������ �־�����.

���
ù° �ٺ��� N-1���� �ٿ� �� ����� �θ� ��� ��ȣ�� 2�� ������ ������� ����Ѵ�.

���� �Է� 1
7
1 6
6 3
3 5
4 1
2 4
4 7
���� ��� 1
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