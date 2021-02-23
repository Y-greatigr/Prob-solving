#include <iostream>
#include <queue>
using namespace std;
int** a;
int** b;
int n;
void bfs(int i) {
	queue<int> q;
	q.push(i);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int j = 0; j < n; j++) {
			if (x == j)
				continue;
			if (a[x][j] == 1 && b[x][j] == 0) {
				a[i][j] = 1;
				q.push(j);
				b[x][j] = 1;
			}
		}
	}
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++)
			b[j][k] = 0;
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;

	a = new int* [n];
	b = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		b[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			b[i][j] = 0;
		}
	}

	for(int i=0;i<n;i++)
		bfs(i);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << '\n';
		delete[]a[i];
		delete[]b[i];
	}
	delete[]a;
	delete[]b;
	return 0;
}