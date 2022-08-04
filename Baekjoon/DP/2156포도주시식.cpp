#include <iostream>
#include <algorithm>
using namespace std;
int a[10001];
int d[10001];
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n; cin >> n;
	for (int i = 3; i < n + 3; i++)
		cin >> a[i];
	int maxi = 0;
	for (int i = 3; i < n + 3; i++) {
		d[i] = max(a[i] + d[i - 2], a[i] + a[i - 1] + d[i - 3]);
		d[i] = max(d[i], d[i - 1]);
		maxi = max(maxi, d[i]);
	}
	cout << maxi;
	return 0;
}