#include <iostream>
#include <vector>
using namespace std;

int P, N;
vector<long long> v;
void input() {
	cin >> P >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
}
void solution() {
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		sum %= 1000000007;
		sum *= P;
		sum += v[i];
	}
	cout << sum % 1000000007;
}
void solve() {
	input();
	solution();
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}