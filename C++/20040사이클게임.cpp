#include <iostream>
using namespace std;

int N, M;
int p[500000];

int find(int c) {
	if (p[c] == c)return c;
	else return p[c] = find(p[c]);
}
bool uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return true;
	else p[a] = b;
	return false;
}

void solution() {
	for(int i=1;i<=M;i++) {
		int a, b; cin >> a >> b;
		if (uni(a, b)) {
			cout << i; return;
		}
	}
	cout << 0;
}
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) p[i] = i;
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