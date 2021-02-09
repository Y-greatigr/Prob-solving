#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	string* a = new string[n];
	string* b = new string[m];
	vector <string> v;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(b, b + m);

	for (int i = 0; i < n; i++) {
		string se = a[i];
		int st = 0;
		int en = m;
		while (st < en) {
			int mid = (st + en) / 2;
			if (b[mid] == se) {
				v.push_back(se);
				break;
			}
			else if (b[mid] < se)
				st = mid + 1;
			else
				en = mid;
		}
	}
	cout << v.size() << '\n';
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';

	return 0;
}