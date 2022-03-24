#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N;
int arr[1001];
bool visited[1001];
vector<int> v[1001];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	memset(visited, false, sizeof(visited));
}
void solution() {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i])
			continue;
		int ind = i;
		while (1) {
			v[cnt].push_back(ind);
			if (visited[ind])
				break;
			visited[ind] = true;
			ind = arr[ind];
		}
		cnt++;
	}

	cout << cnt;
	for (int i = 0; i < cnt; i++) {
		cout << '\n' << v[i][0];
		for (int j = 1; j < v[i].size(); j++)
			cout << " " << v[i][j];
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