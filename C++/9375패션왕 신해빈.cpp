#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	string a, b;
	while(n--){
		int w;
		cin >> w;
		map<string, int> wear;
		for (int i = 0; i < w; i++) {
			cin >> a >> b;
			if (wear.count(b) > 0)
				wear[b]++;
			else
				wear.insert(make_pair(b, 1));
		}
		map<string, int>::iterator it;
		int count = 1;
		for (it = wear.begin(); it != wear.end(); ++it) {
			count = count * (it->second + 1);
		}
		cout << count - 1 << '\n';
	}

	return 0;
}