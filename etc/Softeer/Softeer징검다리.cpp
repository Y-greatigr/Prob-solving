#include <iostream>
using namespace std;

int N;
int a[3000];
int ans[3000];
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		ans[i] = 1;
	}
}
void solution() {
	int maxi = 1;
	for (int i = 1; i < N; i++) {
		int max = 0;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				if (max < ans[j])
					max = ans[j];
			}
		}
		ans[i] = max + 1;
		if (maxi < ans[i])
			maxi = ans[i];
	}
 	cout << maxi;
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