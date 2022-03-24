#include <iostream>
#include <string>
using namespace std;

string a, b;
void input() {
	cin >> a >> b;
}
void solution() {
	while (1) {
		if (a.find(b) != string::npos) {
			string c, d;
			int ind = a.find(b);
			c = a.substr(0, ind);
			d = a.substr(ind + b.length());
			a = c;
			if (d.find(b) != string::npos) {
				int ind = d.find(b);
				c = d.substr(0, ind);
				d = d.substr(ind + b.length());
				a = a + c + d;
			}
			else
				a = a + d;
		}
		else {
			break;
		}
	}
	cout << a;
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