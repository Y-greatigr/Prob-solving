#include <iostream>
#include <string>
using namespace std;

int M1, M2, N;
string m1, m2;
string message;
string real_msg = "";

void input() {
	cin >> M1 >> M2 >> N;
	cin >> m1 >> m2 >> message;
}
void ans(string k) {
	if (real_msg.find(k) == string::npos)
		cout << "NO" << '\n';
	else
		cout << "YES" << '\n';
}
void solution() {
	char c = '@';
	for (int i = 0; i < N; i++) {
		if (message[i] == c)
			continue;
		real_msg += message[i];
		c = message[i];
	}
	ans(m1);
	ans(m2);
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