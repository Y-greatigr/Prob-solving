#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int N;
int cnt = 0;
char a[202][101];
int maxx = 100, minn = 100;
void input() {
	cin >> N;
	int curx = 100;
	char cu='2';
	memset(a, '.', sizeof(a));
	for (int i = 0; i < N; ++i) {
		char b; cin >> b;
		if (b == '+') {
			if (cu == '+')curx--;
			a[curx][i] = '/';
			//curx--;
			if (curx < minn)minn = curx;
		}
		else if (b == '-') {
			if (cu == '-' || cu=='=')curx++;
			a[curx][i] = '\\';
			//curx++;
			if (curx > maxx)maxx = curx;
		}
		else {
			if (cu == '+')curx--;
			a[curx][i] = '_';
			if (curx < minn)minn = curx;
		}
		cu = b;
	}
}

void solution() {
	for (int i = minn; i <=maxx;i++) {
		for (int j = 0; j < N; j++) {
			cout << a[i][j];
		}
		cout << '\n';
	}
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