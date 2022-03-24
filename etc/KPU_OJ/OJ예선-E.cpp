#include <iostream>
#include <algorithm>
using namespace std;

int N;
int a[200000];
int d;
void input() {
	cin >> N;
	d = N * (N + 1) / 2;
	for (int i = 0; i < d; i++) {
		cin >> a[i];
	}
}
void solution() {
	int cur = 1;
	int term = 1;
	int max = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)a[cur] = a[cur] + a[cur - term];
			else if (j == i)a[cur+j] = a[cur+j] + a[cur+j - term-1];
			else {
				a[cur+j] = (a[cur+j - term] > a[cur+j - term - 1]) ? a[cur+j]+a[cur+j - term]: a[cur+j] + a[cur+j - term-1];
			}
			if (max < a[cur + j])max = a[cur + j];
		}
		term += 1;
		cur += i+1;
	}
	if (d == 1)cout << a[0];
	else cout << max;
}
void solve() {
	input();
	solution();
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}