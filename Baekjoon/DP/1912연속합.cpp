#include <bits/stdc++.h>
#define FastIO cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    FastIO;
    int n, dp = 0, ans = -1001; cin >> n;
	for (int i = 0; i < n; i++) {
        int a;cin>>a;
        dp=max(dp,0)+a;
        ans=max(dp,ans);
	}
	cout << ans;
    return 0;
}