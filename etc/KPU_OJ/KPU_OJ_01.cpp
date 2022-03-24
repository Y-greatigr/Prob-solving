#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int N;
int a[1003002];
void input() {
	cin >> N;
	memset(a, 0, sizeof(a));
	a[0] = 1; a[1] = 1;
	for (int i = 2; i <= 1002; i++) {
		for (int j = i; j <= 5001501; j++) {
			if (i * j > 1003001)
				break;
			if (a[i * j] > 0)
				continue;
			a[i * j] = 1;
		}
	}
}
void solution() {
	int M = N;
	while (1) {
		if (!a[M]) {
			bool flag = true;
			string b = to_string(M);
			for (int j = 0; j < b.length(); j++) {
				if (b[b.length() - (j + 1)] != b[j]) {
					flag = false;
					break;
				}
			}
			if (flag)
				break;
		}
		M++;
	}
	cout << M;
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