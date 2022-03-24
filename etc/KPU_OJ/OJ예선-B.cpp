#include <iostream>
using namespace std;

int A, B;
int arr[21][21];
void input() {
	cin >> A >> B;
	int cur = 1;
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < B; j++) {
			arr[i][j] = cur++;
		}
	}
}
void solution() {
	cout << 'M' << '\n';
	for (int i = 0; i < A; i++) {
		for (int j = 0; j < B; j++) {
			if (j == B - 1)cout << arr[i][j];
			else cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	cout << 'R' << '\n';
	for (int i = 0; i < B; i++) {
		for (int j = A-1; j >=0; j--) {
			if (j == 0)cout << arr[j][i];
			else cout << arr[j][i] << " ";
		}
		cout << '\n';
	}
	cout << 'L' << '\n';
	for (int i = B - 1; i >= 0; i--) {
		for (int j = 0; j < A; j++) {
			if (j == A - 1)cout << arr[j][i];
			else cout << arr[j][i] << " ";
		}
		cout << '\n';
	}
	cout << 'T' << '\n';
	for (int i = 0; i < B; i++) {
		for (int j = 0; j < A; j++) {
			if (j == A - 1)cout << arr[j][i];
			else cout << arr[j][i] << " ";
		}
		if (i == B - 1)break;
		cout << '\n';
	}
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