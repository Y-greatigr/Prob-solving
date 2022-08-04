#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[4][50001];
vector<int> a;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int d, n; cin >> n;
	a.resize(n + 1);
	a[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> d;
		a[i] = a[i - 1] + d;
	}
	int r; cin >> r;
	for (int i = 1; i <= 3; i++) {
		for (int j = i * r; j <= n; j++) {
			dp[i][j] = max(dp[i][j - 1], 
				dp[i - 1][j - r] + a[j] - a[j - r]);
		}
	}
	cout << dp[3][n];

	return 0;
}