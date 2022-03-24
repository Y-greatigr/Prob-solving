#include <iostream>
#include <cstdlib>
using namespace std;

int N;
int a[10001][2];
void input() {
	cin >> N;
	int b, c;
	for (int i = 1; i <= N; i++) {
		cin >> b >> c;
		a[i][0] += (b + a[i - 1][0]);
		a[i][1] += (c + a[i - 1][1]);
	}
}
void solution() {
	int max = 0;
	int winner = 0;
	for (int i = 1; i <= N; i++) {
		int gap = abs(a[i][0] - a[i][1]);
		if (gap > max) {
			max = gap;
			winner = (a[i][0] > a[i][1]) ? 1 : 2;
		}
	}
	cout << winner << " " << max;
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