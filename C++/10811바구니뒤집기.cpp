#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
void ch(int a, int b) {
	vector<int> du(b + 1);
	int k = a;
	for (int i = b; i >= a; i--)
		du[k++] = v[i];
	for (int i = a; i <= b; i++)
		v[i] = du[i];
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m, a, b;
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
		v[i] = i;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		ch(a, b);
	}
	for (int i = 1; i <= n; i++)
		cout << v[i] << " ";
	return 0;
}