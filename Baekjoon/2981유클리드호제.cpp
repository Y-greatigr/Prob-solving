#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int euc(int a, int b) {
	return a % b ? euc(b, a % b) : b;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int d = v[1] - v[0];
	for (int i = 2; i < n; i++) {
		d = euc(d, v[i] - v[i - 1]);
	}
	vector<int> a;
	int j;
	for (j = 2; j * j <= d; j++) {
		if (d % j == 0) {
			a.push_back(j);
			a.push_back(d / j);
		}
	}
	a.push_back(d);
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	return 0;
}