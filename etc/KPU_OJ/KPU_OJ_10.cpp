#include <iostream>
using namespace std;

int S, P, k;
void input() {
	cin >> S >> P >> k;
}
void one() {
	if (S != P)
		cout << "NO";
	else
		cout << S;
}
void two() {
	for (int i = 1; i < S; i++) {
		int j = S - i;
		if (i * j == P) {
			cout << i << " " << j; 
			return;
		}
	}
	cout << "NO";
}
void three() {
	for (int i = 1; i < S; i++) {
		for (int j = 1; j < S; j++) {
			if (i + j >= S)
				break;
			int k = S - i - j;
			if (i * j * k == P) {
				cout << i << " " << j << " " << k;
				return;
			}
		}
	}
	cout << "NO";
}
void four() {
	for (int i = 1; i < S; i++) {
		for (int j = 1; j < S; j++) {
			if (i + j >= S - 1)
				break;
			for (int k = 1; k < S; k++) {
				if (i + j + k > S)
					break;
				int l = S - i - j - k;
				if (i * j * k * l == P) {
					cout << i << " " << j << " " << k << " " << l;
					return;
				}
			}
		}
	}
	cout << "NO";
}
void solution() {
	if (k == 1)
		one();
	else if (k == 2)
		two();
	else if (k == 3)
		three();
	else
		four();
}
void solve() {
	input();
	solution();
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}