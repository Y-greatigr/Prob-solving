#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, b;
	cin >> n >> m >> b;
	int** v = new int*[n];
	int mind = 257;
	int maxd = -1;
	for (int i = 0; i < n; i++) {
		v[i] = new int[m];
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			mind = min(mind, v[i][j]);
			maxd = max(maxd, v[i][j]);
		}
	}
	int final_time = 99999999;
	int final_height = 0;
	for (int k = mind; k <= maxd; k++) {
		int block = b;
		int time = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int dif = v[i][j] - k;
				if (dif >= 0) {
					time += 2 * dif;
					block += dif;
				}
				else {
					time += dif*(-1);
					block += dif;
				}
			}
		}
		if (block >= 0) {
			if (time <= final_time) {
				final_time = time;
				final_height = k;
			}
		}
	}
	cout << final_time << " " << final_height;
	for (int i = 0; i < n; i++) {
		delete v[i];
	}
	delete[]v;
	return 0;
}