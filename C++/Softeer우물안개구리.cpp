#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N, M;
int mem[100001];
vector<int> fnd[100001];
void input() {
	int a, b;
	cin >> N >> M;
	memset(mem, 0, N);
	for (int i = 1; i <= N; i++)
		cin >> mem[i];
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		fnd[a].push_back(b);
		fnd[b].push_back(a);
	}
}
void solution() {
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		int flag = 1;
		for (int j = 0; j < fnd[i].size(); j++) {
			if (mem[i] <= mem[fnd[i][j]]) {
				flag = 0;
				break;
			}
		}
		if(flag)
			sum++;
	}
	cout << sum;
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