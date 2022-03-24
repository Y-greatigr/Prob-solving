#include <iostream>
using namespace std;

int N, M;
char board[10001];
void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> board[i];
}
void solution() {
	int cnt = 0;
	int cur = 1;
	int dice;
	while (M--) {
		if (cur == 1)
			cnt++;
		cin >> dice;
		if (board[cur] == '+') {
			if (cur + dice <= N)
				cur += dice;
		}
		else {
			if (cur - dice >= 1)
				cur -= dice;
		}
	}
	cout << cnt;
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