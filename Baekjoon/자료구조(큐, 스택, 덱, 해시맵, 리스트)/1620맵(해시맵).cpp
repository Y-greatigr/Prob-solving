#include <iostream>
#include <string>
#include <map>
using namespace std;
string na[100001];
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	map<string, int> hs;
	string a;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		hs.insert(pair<string, int>(a, i));
		na[i] = a;
	}
	while (m--) {
		cin >> a;
		if(isdigit(a[0]))
			cout << na[stoi(a)] << '\n';
		else
			cout << hs[a] << '\n';
	}
	return 0;
}