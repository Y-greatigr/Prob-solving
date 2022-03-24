#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int k, n;
	cin >> k >> n;
	long long sh = 1;
	long long lo = 0;
	vector<long long> v(k);

	for (int i = 0; i < k; i++) {
		cin >> v[i];
		lo = max(lo, v[i]);
	}

	long long max = 0;
	while (sh <= lo) {
		long long mid = (sh + lo) / 2;
		long long count = 0;
		for (int i = 0; i < k; i++) {
			count += v[i] / mid;
		}
		if (count >= n) {
			if (mid > max)
				max = mid;
			sh = mid + 1;
		}
		else
			lo = mid - 1;
	}
	cout << max;
	return 0;
}