#include <iostream>
#include <algorithm>
using namespace std;
int a[2][100000];
int dp[2][100001];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t, n; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[0][i];
        for (int i = 0; i < n; i++)
            cin >> a[1][i];
        dp[0][0] = a[0][0]; dp[1][0] = a[1][0];
        dp[0][1] = a[0][1] + a[1][0]; dp[1][1] = a[1][1] + a[0][0];
        for (int i = 2; i < n; i++) {
            dp[0][i] = max(dp[1][i - 2] + a[0][i], dp[1][i - 1] + a[0][i]);
            dp[1][i] = max(dp[0][i - 2] + a[1][i], dp[0][i - 1] + a[1][i]);
        }
        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }
    return 0;
}