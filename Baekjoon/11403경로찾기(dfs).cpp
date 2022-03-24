#include <iostream>
#include <vector>
using namespace std;
vector<int> v[100];
int a[100][100];
int n;
void dfs(int i, int k) {
	for (int j = 0; j < v[i].size(); j++) {
		int e = v[i][j];
		if (a[k][e])
			continue;
		a[k][e] = 1;
		dfs(e, k);
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	int d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> d;
			if (d == 1)
				v[i].push_back(j);
		}
	}

	for (int i = 0; i < n; i++)
		dfs(i, i);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}