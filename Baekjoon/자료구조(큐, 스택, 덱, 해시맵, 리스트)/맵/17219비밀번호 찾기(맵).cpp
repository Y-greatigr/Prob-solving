#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string site, passwd;
	map<string, string> na;
	while (n--) {
		cin >> site >> passwd;
		na.insert(pair<string, string>(site, passwd));
	}
	while (m--) {
		cin >> site;
		cout << na[site] << '\n';
	}
	return 0;
}