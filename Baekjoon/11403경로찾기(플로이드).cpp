#include <iostream>
using namespace std;
int** a;
void floyd(int n) {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][k] == 1 && a[k][j] == 1) {
					a[i][j] = 1;
				}
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n; cin >> n;

	a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	floyd(n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << '\n';
		delete[]a[i];
	}
	delete[]a;
	return 0;
}