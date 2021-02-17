#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	map<char, int> ma;
	ma.insert(make_pair('0', 0));
	ma.insert(make_pair('1', 0));
	ma.insert(make_pair('2', 0));
	ma.insert(make_pair('3', 0));
	ma.insert(make_pair('4', 0));
	ma.insert(make_pair('5', 0));
	ma.insert(make_pair('6', 0));
	ma.insert(make_pair('7', 0));
	ma.insert(make_pair('8', 0));
	int max = 0;
	int nextMax = 0;
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '9')
			s[i] = '6';
		ma[s[i]]++;
		if (ma[s[i]] > max) {
			max = ma[s[i]];
		}
	}

	for (auto it = ma.begin(); it != ma.end(); it++) {
		if (it->first == '6')
			continue;
		if (it->second > nextMax)
			nextMax = it->second;
	}
	if (ma['6'] == max) {
		if (max / 2 < nextMax)
			cout << nextMax;
		else
			cout << max / 2 + max % 2;
	}
	else
		cout << max;

	return 0;
}