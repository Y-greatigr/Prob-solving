#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int a[101][101];
int solution(int n, vector<vector<int>> results) {
	int answer = 0; memset(a, 0, sizeof(a));
	for (int i = 0; i < results.size(); i++) a[results[i][0]][results[i][1]] = 1;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][k] && a[k][j]) a[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (a[i][j] || a[j][i])cnt++;
		}
		if (cnt == (n - 1))answer++;
	}
	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<vector<int>> a = { {4,3} ,{4, 2},{3, 2},{1, 2},{2, 5} };
	cout << solution(5, a);
	return 0;
}