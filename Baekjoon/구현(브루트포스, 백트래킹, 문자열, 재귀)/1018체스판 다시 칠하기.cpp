#include <iostream>

using namespace std;
char a[50][50];

int check(int n, int m) {

	int min = 32;
	for (int p = 0; p <= n - 8; p++) {
		for (int k = 0; k <= m - 8; k++) {
			char c = a[p][k];
			int de = (p + k) % 2;
			int sum = 0;
			for (int i = p; i < p + 8; i++) {
				for (int j = k; j < k + 8; j++) {
					if ((i + j) % 2 == de) {
						if (a[i][j] != c)
							sum++;
					}
					else {
						if (a[i][j] == c)
							sum++;
					}					
				}
			}
			if (sum > 32)
				sum = 64 - sum;
			if (min > sum)
				min = sum;
		}
	}
	return min;
}
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
		}
	}
	cout<<check(N, M);
	return 0;
}