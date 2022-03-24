#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int fac[20000];
int N, K;
string a;
void input() {
	cin >> N >> K;
	cin >> a;
}
void solution() {
	int cnt = 0;
	memset(fac, -1, sizeof(fac));
	for (int i = 0; i < N; i++) {
		if (a[i] == 'H')
			continue;
		int flag = 0;
		for (int j = i - K; j < i; j++) {
			if (j < 0 || j >= N || fac[j]==1 || a[j]=='P')
				continue;
			cnt++;
			fac[j] = 1;
			flag = 1;
			break;
		}
		if (flag)
			continue;
		for (int j = i + 1; j <= i + K; j++) {
			if (j < 0 || j >= N || fac[j] == 1 || a[j] == 'P')
				continue;
			cnt++;
			fac[j] = 1;
			break;
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