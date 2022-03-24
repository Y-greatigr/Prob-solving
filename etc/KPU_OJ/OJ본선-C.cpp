#include <iostream>
#include<algorithm>
using namespace std;

int dp[301][2];
int n;
int ar[301];
bool flag[301] = { false, };
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> ar[i];
}
void solution() {
	dp[0][0] = 0;
	dp[0][1] = 0;

	dp[1][0] = ar[1];
	dp[1][1] = ar[1];

	dp[2][0] = ar[2];
	dp[2][1] = ar[2] + dp[1][1];

	dp[3][0] = ar[3] + dp[1][0];
	if (dp[2][0] > dp[1][0]) { 
		dp[3][1] = ar[3] + dp[2][0];
		flag[3] = true; 
	}
	else {
		dp[3][1] = ar[3] + dp[1][0];
		flag[3] = false;
	}

	for (int i = 4; i <= n; i++) {
		if (flag[i-1]) {
			dp[i][0] = ar[i]+max(dp[i - 2][0], dp[i - 2][1]);
			if (dp[i - 1][0] > dp[i - 2][1]) {
				flag[i] = true;
				dp[i][1] = ar[i] + dp[i - 1][0];
			}
			else {
				flag[i] = false;
				dp[i][1] = ar[i] + dp[i - 2][1];
			}
		}
		else {
			dp[i][0] = ar[i] + max(dp[i - 2][0], dp[i - 2][1]);
			dp[i][1] = ar[i] + max(dp[i - 1][0], dp[i - 1][1]);
			flag[i] = true;
		}
	}
	cout << max(dp[n][0], dp[n - 1][0]);
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