#include <iostream>
#include <vector>
using namespace std;

double a[1000001] = { 0 };
vector<double>f;
int N, K;
void input() {
	cin >> N >> K;
	double b, c = 0;
	a[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> b;
		a[i] = b + c;
		c = a[i];
	}
}
void solution() {
	cout << fixed;
	cout.precision(2);
	for (int k = 0; k < K; k++) {
		int b, c;
		cin >> b >> c;
		f.push_back((a[c] - a[b - 1]) / (c - b + 1));
	}
	for (int i = 0; i < f.size(); i++)
		cout << f[i] << '\n';
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