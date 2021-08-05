#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[1001][1000];
string a, b = "_";
int an = 0, bn = 0;

void input() {
	string k;
	cin >> a >> k;
	b += k;
	an = a.length();
	bn = b.length();
	for (int i = 0; i < an; i++)
		arr[0][i] = 0;
}
void solution() {
	for (int i = 1; i < bn; i++) {
		for (int j = 0; j < an; j++) {
			if (a[j] == b[i]) {
				if (j != 0)
					arr[i][j] = arr[i - 1][j - 1] + 1;
				else
					arr[i][j] = 1;
			}
			else {
				if (j != 0)
					arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
				else
					arr[i][j] = arr[i - 1][j];
			}
		}
	}
	cout << arr[bn - 1][an - 1];
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