#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
int** a;
int* b;
int n, m;
vector<int> v;
void dfs(int k) {
	b = new int[n + 1];
	for (int i = 1; i <= n; i++)
		b[i] = -1;
	b[k] = 0;
	queue<int>q;
	q.push(k);
	
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (a[tmp][i] == 1 && b[i] == -1) {
				q.push(i);
				b[i] = b[tmp] + 1;
			}
		}
	}
	int total = 0;
	total = accumulate(b+1, b+n+1, total);
	v.push_back(total);
	delete[] b;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	a = new int* [n + 1];
	for (int i = 0; i <= n; i++)
		a[i] = new int[n + 1];

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}

	for (int i = 1; i <= n; i++)
		dfs(i);

	int f = *min_element(v.begin(), v.end());
	vector<int> d;
	for (int i = 0; i < n; i++) {
		if (v[i] == f)
			d.push_back(i + 1);
	}
	cout << *min_element(d.begin(), d.end());

	for (int i = 0; i <= n; i++)
		delete[]a[i];
	delete[]a;
	return 0;
}