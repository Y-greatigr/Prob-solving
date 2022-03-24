#include <iostream>
using namespace std;

long long N, M;
int arr[1'000'001];
int maxi = 0;
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) { 
		cin >> arr[i]; 
		if (maxi < arr[i])maxi = arr[i];
	}
}
void solution() {
	int a = 0;
	int b = maxi;
	int answer=0;
	while (a < b) {
		int ave = (a + b) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] <= ave)continue;
			sum += arr[i] - ave;
		}
		if (sum >= M) {
			a = ave + 1;
			answer = ave;
		}
		else b = ave;
	}
	cout << answer;
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