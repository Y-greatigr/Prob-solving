#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		v[i] = i + 1;

	int ind = k - 1;
	int s = n;
	cout << "<";
	while (s > 1) {
		cout << v[ind] << ", ";
		v.erase(v.begin() + ind);
		ind += k - 1;
		s = v.size();
		if (ind >= s) {
			ind = ind % s;
		}
	}
	cout << v[0] << ">";
	return 0;
}