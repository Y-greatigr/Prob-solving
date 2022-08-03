#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n; cin >> n;
	int maxi = 0;
	vector<vector<int>> v(n);

	for (int i = 0; i < n; i++) {
		v[i].resize(i + 1);
		for (int j = 0; j <= i; j++)
			cin >> v[i][j];
	}
	maxi = v[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0)
				v[i][0] += v[i - 1][0];
			else if (j == i)
				v[i][j] += v[i - 1][j - 1];
			else
				v[i][j] += max(v[i - 1][j], v[i - 1][j - 1]);
			maxi = max(maxi, v[i][j]);
		}
	}
	cout << maxi;
	return 0;
}