#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> a;
int er;
int co = 0;
void dfs(int n) {
	if (n == er)
		return;
	if (a[n].size() == 0)
		co++;
	else {
		if (a[n].size() == 1) {
			if (a[n][0] == er) {
				co++;
				return;
			}
		}
		for(int i=0;i< a[n].size();i++)
			dfs(a[n][i]);
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, x, root = 0;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == -1) {
			root = i;
			continue;
		}
		a[x].push_back(i);
	}
	cin >> er;
	dfs(root);
	cout << co;
	return 0;
}