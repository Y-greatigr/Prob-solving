#include <iostream>
#include <vector>
using namespace std;

int aa, bb, cc;
int a[50000];
int b[50000];
int c[50000];
vector<int> v;

void input() {
	cin >> aa >> bb >> cc;
	for (int i = 0; i < aa + bb + cc; i++) {
		if (i < aa) cin >> a[i];
		else if (i < aa + bb) cin >> b[i - aa];
		else cin >> c[i - aa - bb];
	}
}
void surplus(int* ar1, int* ar2, int ii, int jj, int lim1, int lim2) {
	while (ii < lim1 && jj < lim2) {
		if (ar1[ii] == ar2[jj]) {
			v.emplace_back(ar1[ii]);
			ii++; jj++;
		}
		else if (ar1[ii] < ar2[jj]) ii++;
		else jj++;
	}
}
void solution() {
	int i = 0, j = 0, k = 0;
	while (i < aa && j < bb && k < cc) {
		if (a[i] == b[j] && b[j] == c[k]) {
			v.emplace_back(a[i]);
			i++; j++; k++;
		}
		else if (a[i] == b[j]) {
			if (c[k] < a[i]) {
				k++;
				continue;
			}
			v.emplace_back(a[i]);
			i++; j++;
		}
		else if (a[i] == c[k]) {
			if (b[j] < a[i]) {
				j++;
				continue;
			}
			v.emplace_back(a[i]);
			i++; k++;
		}
		else if (b[j] == c[k]) {
			if (a[i] < b[j]) {
				i++;
				continue;
			}
			v.emplace_back(b[j]);
			j++; k++;
		}
		else {
			if (a[i] < b[j]) {
				if (c[k] < a[i]) k++;
				else i++;
			}
			else {
				if (c[k] < b[j]) k++;
				else j++;
			}
		}
	}
	if (i < aa) {
		if (j < bb)
			surplus(a, b, i, j, aa, bb);
		else if (k < cc)
			surplus(a, c, i, k, aa, cc);
		else {}
	}
	else if (j < bb) {
		if (k < cc)
			surplus(b, c, j, k, bb, cc);
		else {}
	}
	else {}

	cout << v.size() << '\n';
	for (int h = 0; h < v.size(); h++)
		cout << v[h] << '\n';
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