#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;
void input() {
	cin >> N >> M;
	int a = 0;
	int t;
	v.resize(N + 1);
	v[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> t;
		v[i] = t + a;
		a = v[i];
	}
}
void solution() {
	while (M--) {
		int a, b;
		cin >> a >> b;
		cout << v[b] - v[a - 1] << '\n';
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