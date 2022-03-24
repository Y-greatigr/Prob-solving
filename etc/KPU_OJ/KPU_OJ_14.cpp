#include <iostream>
#include <vector>
using namespace std;

int N;
int ar1[8][8];
int ar2[8][8];
int cnt[9];

int up(int col) {
	int tmp = ar1[0][col];
	for (int i = 1; i < N; i++)
		ar1[i - 1][col] = ar1[i][col];
	ar1[N - 1][col] = tmp;
	return col + 1;
}
int down(int col) {
	int tmp = ar1[N - 1][col];
	for (int i = N - 1; i > 0; i--)
		ar1[i][col] = ar1[i - 1][col];
	ar1[0][col] = tmp;
	return -col - 1;
}
void right(int row) {
	int tmp = ar1[row][N - 1];
	for (int i = N - 1; i > 0; i--)
		ar1[row][i] = ar1[row][i - 1];
	ar1[row][0] = tmp;
}
bool check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (ar1[i][j] != ar2[i][j])
				return false;
	}
	return true;
}
bool check(int row) {
	for (int i = 0; i < N; i++) {
		if (ar1[row][i] != ar2[row][i])
			return false;
	}
	return true;
}
void print() {
	cout << "YES" << '\n' << cnt[0];
	for (int i = 1; i <= N; i++) {
		if (cnt[i] == 0)
			continue;
		int wow = cnt[i];
		for (int j = 0; j < wow; j++)
			cout << " " << i;
	}
}
void dfs(int row) {
	if (check()) {
		print();
		exit(0);
	}
	if (row >= N)
		return;

	for (int i = 0; i < N; i++) {
		cnt[row + 1] = i;
		if (check(row))
			dfs(row + 1);
		right(row);
	}
	cnt[row + 1] = 0;
}
void input() {
	cin >> N;
	for (int i = 0; i < 2 * N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < N)
				cin >> ar1[i][j];
			else
				cin >> ar2[i - N][j];
		}
	}
}
void solution() {
	for (int i = 0; i < 2 * N; i++) {
		int ind;
		if (!(i % 2)) ind = up(i / 2);
		else ind = down(i / 2);
		cnt[0] = ind;

		dfs(0);

		if (ind < 0) up(-(ind + 1));
		else down(ind - 1);
	}
	cout << "NO";
}
void solve() {
	input();
	solution();
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}